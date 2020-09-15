/********************************************************************
* Copyright (C) 2015 by Interstel Technologies, Inc.
*   and Hawaii Space Flight Laboratory.
*
* This file is part of the COSMOS/core that is the central
* module for COSMOS. For more information on COSMOS go to
* <http://cosmos-project.com>
*
* The COSMOS/core software is licenced under the
* GNU Lesser General Public License (LGPL) version 3 licence.
*
* You should have received a copy of the
* GNU Lesser General Public License
* If not, go to <http://www.gnu.org/licenses/>
*
* COSMOS/core is free software: you can redistribute it and/or
* modify it under the terms of the GNU Lesser General Public License
* as published by the Free Software Foundation, either version 3 of
* the License, or (at your option) any later version.
*
* COSMOS/core is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* Lesser General Public License for more details.
*
* Refer to the "licences" folder for further information on the
* condititons and terms to use this software.
********************************************************************/

// This is a simple propagator program without COSMOS node dependecy (is that possible?)
// , it starts propagating from a given state
// (load from cosmosroot-state.ini?)

#include "physics/physicslib.h"
#include "math/mathlib.h"
#include "agent/agentclass.h"
#include "support/jsonlib.h"
#include "support/datalib.h"
#include "support/print_utils.h"

#include <sys/stat.h>
#include <typeinfo>

using namespace std;

// ------------------------------------------------------------------
// User config

// config agent
string node_name = "cubesat1";
string agent_name = "propagator_simple";

//bool    use_agent       = true;
//bool    use_propagator   = true; //

// ------------------------------------------------------------------
// Other vars

// general purpose buffer
char buffer[255] = "";

Agent *agent;
vector<shorteventstruc> eventdict;
vector<shorteventstruc> events;
string mainjstring={0,0,0};

void printMjdAndDateTime(double mjd){
    cout << mjdToGregorianFormat(mjd) << setprecision(10) << " (MJD=" <<  mjd << ")"; // << endl;
}

int main(int argc, char* argv[]){

    // for propagator
    int32_t order   = 6; // integration order
    int32_t mode    = 1; // attitude mode (0 - propagate?, 1-LVLH, ...)
    double dt       = 1; // >> check with Eric .1 or 1?

    double triger_time = 0;
    double iteration_rate = 1; //in sec
    double trigger_offset_ms = 10; // ms before sending the command
    int precision = 1/iteration_rate;
    double sleep_time = 0.7*iteration_rate;
    double set_time = 0;
    double elapsed_seconds = 0;
    double utc_now;
    int32_t iretn;

    // for time profiling
    ElapsedTime ep;
    ep.print = false;

    PrintUtils print;

    locstruc state; // Set state container
    locstruc initState; // Set initial state

    // break down state vector
    // position
    double x = state.pos.eci.s.col[0];
    double y = state.pos.eci.s.col[1];
    double z = state.pos.eci.s.col[2];

    // velocity
    double vx = state.pos.eci.v.col[0];
    double vy = state.pos.eci.v.col[1];
    double vz = state.pos.eci.v.col[2];

    // attitude quaternion
    double q1 = state.att.icrf.s.d.x;
    double q2 = state.att.icrf.s.d.y;
    double q3 = state.att.icrf.s.d.z;
    double q4 = state.att.icrf.s.w;

    // --------------------------------------------------------------

    switch (argc)
    {
    case 1:
        // use default node 'cubesat1'
        break;
    case 2:
        // use node given by user input
        node_name = argv[1];
        break;
    case 3:
        // use time given by user input
        //        mjdstart = atof(argv[2]);
        break;
    default:
        cout << "Usage: propogator_simple nodename [mjd|0]" << endl;
        exit (-1);
        break;
    }

    //	cout << "-----------------------------------------------" << endl;
    //	cout << "|      COSMOS Propagator Example              |" << endl;
    //	cout << "-----------------------------------------------" << endl;

    // Establish the command channel and heartbeat
    agent = new Agent(node_name, agent_name);

    if (agent->last_error()<0)
    {
        cout<<"agent_setup_server failed (returned <"<<AGENT_ERROR_JSON_CREATE<<">)"<<endl;
        exit (AGENT_ERROR_JSON_CREATE);
    }

    //agent->cinfo->physics.mode = mode;
    //json_clone(cinfo);

    //load_dictionary(eventdict, cinfo, (char *)"events.dict");


    // start timer
    ep.tic();

    // ------------------------------------
    // load state.ini

    cout << "Loading state.ini info from " << node_name << " node (node must exist in cosmos/nodes) "  << endl;

    struct stat fstat;
    FILE* fdes;
    string fname = get_nodedir((node_name.c_str()));
    fname += "/state.ini";

    pos_clear(initState);

    if ((iretn=stat(fname.c_str(), &fstat)) == 0 && (fdes=fopen(fname.c_str(),"r")) != NULL)
    {
        char* ibuf = (char *)calloc(1,fstat.st_size+1);

        fread(ibuf, 1, fstat.st_size, fdes);
        //		fgets(ibuf,fstat.st_size,fdes);
        json_parse(ibuf, agent->cinfo);

        free(ibuf);

        initState.pos.eci   = agent->cinfo->node.loc.pos.eci;
        //initState.att.icrf  = agent->cinfo->node.loc.att.icrf;
        initState.utc       = agent->cinfo->node.loc.pos.eci.utc;

        cout << "Sucessfully found state.ini"  << endl;

        cout << "UTC from state.ini   : ";
        printMjdAndDateTime(initState.utc);
        print.endline();
        print.vector("Initial ECI Position : ", initState.pos.eci.s, " m", 3);print.endline();
        print.vector("Initial ECI Velocity : ", initState.pos.eci.v, " m/s",3);print.endline();
        //print.end();
        cout << "-----------------------------------------------" << endl;

    }
    else
    {
        printf("Unable to open state.ini\n");
        exit (-1);
    }

    ep.toc("load state.ini");

    // propagate the changes to all frames
    initState.pos.eci.pass++;
    pos_eci(&initState);

    // initialize propagator
    //CT 2017-06-26: couldn't find a gj_handle data type for this function to use
    gj_handle gjh;
    gauss_jackson_init_eci(gjh,
                           order,
                           mode,
                           dt,
                           currentmjd(),// use curretn time instead of initState.utc for this demo, otherwise it will take a long time to update
                           initState.pos.eci,
                           initState.att.icrf,
                           agent->cinfo->physics,
                           agent->cinfo->node.loc);

    // propagate state to current time so we get an updated state vector
    // to initialize the GPS sim
    //CT 2017-06-26: couldn't find a gj_handle data type for this function to use
    gauss_jackson_propagate(gjh, agent->cinfo->physics, agent->cinfo->node.loc, currentmjd());

    //get initial sim tim
    double mjd_start_sim = currentmjd();


    // set SOH
    std::string soh = "{\"node_loc_utc\","
                      "\"node_loc_pos_eci\","
                      "\"node_loc_att_icrf\"}" ;

    agent->set_sohstring(soh);

    // --------------------------------------------------------------
    while (agent->running()){ //for agent use
        // get the elapsed seconds from the sim start
        utc_now = currentmjd(0);
        elapsed_seconds = (utc_now - mjd_start_sim)*86400; //+ 50./1000.

        set_time = floor(elapsed_seconds*precision)/precision + iteration_rate;
        triger_time = set_time - trigger_offset_ms/1000.;

        if (elapsed_seconds > triger_time){ // send the command 100 ms before the set time

            // propagate
            gauss_jackson_propagate(gjh, agent->cinfo->physics, agent->cinfo->node.loc,  utc_now);
            state = agent->cinfo->node.loc;

            // break down state vector for this demo
            x = state.pos.eci.s.col[0];
            y = state.pos.eci.s.col[1];
            z = state.pos.eci.s.col[2];

            vx = state.pos.eci.v.col[0];
            vy = state.pos.eci.v.col[1];
            vz = state.pos.eci.v.col[2];

            //
            q1 = state.att.geoc.s.d.x;
            q2 = state.att.geoc.s.d.y;
            q3 = state.att.geoc.s.d.z;
            q4 = state.att.geoc.s.w;

            sprintf(buffer,"%s,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f",
                    mjdToGregorianDDMmmYYYY(utc_now).c_str(),
                    x,y,z,
                    vx,vy,vz,
                    q1,q2,q3,q4);

            //cout << "------------------------------------------------" << endl;
            //print time
            cout << mjdToGregorianFormat(currentmjd());
            cout << " | ";
            cout << seconds2DDHHMMSS(elapsed_seconds) << " | ";

            // print state
            print.vector("pos:",state.pos.geoc.s,1e-3," km | ",0,6);
            print.vector("vel:", state.pos.geoc.v,1e-3, " km/s | ", 2, 3);

            // TODO: print attitude

            // print magnetic field in micro-Tesla
            print.vector("mag field:", agent->cinfo->node.loc.bearth, 1e6, " uT", 1,3);

            // TODO: print solar vector

            // TODO: print moon vector

            // TODO: print nadir vector

            print.endline();

            agent->post(Agent::AgentMessage::SOH, json_of_table(mainjstring, agent->sohtable, agent->cinfo));


            COSMOS_SLEEP(sleep_time); // sleep for 70% of the iteration time

        }

    } // end while

    return iretn;
}




