---
title: Error Messages
permalink: /pages/4-tutorials/concepts/errors.html
layout: series
index: 4.1.3
tags: [software]
keywords: software
series:
    language: "C++"
    prev: /pages/4-tutorials/concepts/libraries.html
---
###  Overview
In COSMOS, there are messages that are created to explain what kind of error may have caused it to fail. These error messages are stored as negative integers inside of the agent class itself. The COSMOS specific errors have values less than -200 (to not coincide with the range of system errors, 1-200). These error messages are grouped in sections of ten based on the cause of the error. For example, JSON errors are given values -251 to -259.The definitions for these error messages can be found below or in the "support" library, in "cosmos-errno.h".

###  GS232B
| Error Type              | COSMOS Error Code  |
|-------------------------|--------------------|
| GS232B_ERROR_OPEN       | -201               |
| GS232B_ERROR_CLOSED     | -202               |
| GS232B_ERROR_OUTOFRANGE | -203               |
| GS232B_ERROR_SEND       | -204               |

###  MicroStrain
| Error Type                   | COSMOS Error Code |
|------------------------------|-------------------|
| MICROSTRAIN_ERROR_OPEN       | -211              |
| MICROSTRAIN_ERROR_CLOSED     | -212              |
| MICROSTRAIN_ERROR_OUTOFRANGE | -213              |
| MICROSTRAIN_ERROR_FAILED     | -214              |
| MICROSTRAIN_ERROR_TOOMANY    | -215              |
| MICROSTRAIN_ERROR_FUNCTION   | -216              |
| MICROSTRAIN_ERROR_SEND       | -217              |

###  Sinclair
| Error Type                 | COSMOS Error Code |
|----------------------------|-------------------|
| SINCLAIR_ERROR_OPEN        | -221              |
| SINCLAIR_ERROR_CLOSED      | -222              |
| SINCLAIR_ERROR_OUTOFRANGE  | -223              |
| SINCLAIR_ERROR_FAILED      | -224              |
| SINCLAIR_ERROR_TOOMANY     | -225              |

 ###   NSP
 | Error Type     | COSMOS Error Code |
 |----------------|-------------------|
 | NSP_ERROR_CRC  | -226              |
 | NSP_ERROR_SIZE | -227              |
 | NSP_ERROR_NACK | -228              |

###  TS2000
| Error Type              | COSMOS Error Code |
|-------------------------|-------------------|
| TS2000_ERROR_OPEN       | -231              |
| TS2000_ERROR_CLOSED     | -232              |
| TS2000_ERROR_OUTOFRANGE | -233              |

###  VMT35
| Error Type             | COSMOS Error Code |
|------------------------|-------------------|
| VMT35_ERROR_RODNUM     | -241              |
| VMT35_ERROR_BYTE       | -242              |
| VMT35_ERROR_OUTOFRANGE | -243              |
| VMT35_ERROR_OPENED     | -244              |
| VMT35_ERROR_CLOSED     | -245              |
| VMT35_ERROR_NACK       | -246              |
| VMT35_ERROR_CRC        | -247              |
| VMT35_ERROR_DEVNAME    | -248              |

###  JSON
| Error Type             | COSMOS Error Code |
|------------------------|-------------------|
| JSON_ERROR_NAME_LENGTH | -251              |
| JSON_ERROR_DATA_LENGTH | -252              |
| JSON_ERROR_INDEX_SIZE  | -253              |
| JSON_ERROR_NOJMAP      | -254              |
| JSON_ERROR_NOENTRY     | -255              |
| JSON_ERROR_EOS         | -256              |
| JSON_ERROR_SCAN        | -257              |
| JSON_ERROR_JSTRING     | -258              |
| JSON_ERROR_NAN         | -259              |
''
###  SLIP
| Error Type         | COSMOS Error Code |
|--------------------|-------------------|
| SLIP_ERROR_CRC     | -261              |
| SLIP_ERROR_PACKING | -262              |
| SLIP_ERROR_BUFFER  | -263              |
###  Agent
| Error Type                 | COSMOS Error Code |
|----------------------------|-------------------|
| AGENT_ERROR_SERVER_RUNNING | -270              |
| AGENT_ERROR_JSON_CREATE    | -271              |
| AGENT_ERROR_REQ_COUNT      | -272              |
| AGENT_ERROR_MEMORY         | -273              |
| AGENT_ERROR_SOCKET         | -274              |
| AGENT_ERROR_CHANNEL        | -275              |
| AGENT_ERROR_BUFLEN         | -276              |
| AGENT_ERROR_NULL           | -277              |
| AGENT_ERROR_DISCOVERY      | -278              |
| AGENT_ERROR_REQUEST        | -279              |

###  Math/GJ
| Error Type               | COSMOS Error Code |
|--------------------------|-------------------|
| MATH_ERROR_GJ_UNDEFINED  | -281              |
| MATH_ERROR_GJ_OUTOFRANGE | -282              |

###  Agent LCM
| Error Type                | COSMOS Error Code |
|---------------------------|-------------------|
| AGENT_ERROR_LCM_CREATE    | -291              |
| AGENT_ERROR_LCM_SUBSCRIBE | -292              |
| AGENT_ERROR_LCM_TIMEOUT   | -293              |
###  RW
| Error Type          | COSMOS Error Code |
|---------------------|-------------------|
| RW_ERROR_OPEN       | -301              |
| RW_ERROR_CLOSED     | -302              |
| RW_ERROR_OUTOFRANGE | -303              |
| RW_ERROR_FAILED     | -304              |
| RW_ERROR_TOOMANY    | -305              |
| RW_ERROR_SEND       | -306              |

###  STK
| Error Type           | COSMOS Error Code |
|----------------------|-------------------|
| STK_ERROR_LOWINDEX   | -311              |
| STK_ERROR_HIGHINDEX  | -312              |
| STK_ERROR_OUTOFRANGE | -313              |
| STK_ERROR_NOTFOUND   | -314              |

###  DEM
| Error Type                    | COSMOS Error Code |
|-------------------------------|-------------------|
| DEM_ERROR_SEMINIT             | -321              |
| DEM_ERROR_OPEN                | -322              |
| DEM_ERROR_INSUFFICIENT_MEMORY | -323              |
| DEM_ERROR_NOTFOUND            | -324              |

###  TLE/Orbit
| Error Type               | COSMOS Error Code |
|--------------------------|-------------------|
| TLE_ERROR_OUTOFRANGE     | -331              |
| ORBIT_ERROR_NOTSUPPORTED | -332              |
| TLE_ERROR_NOTFOUND       | -334              |

###  Node
| Error Type               | COSMOS Error Code |
|--------------------------|-------------------|
| NODE_ERROR_NODE          | -341              |
| NODE_ERROR_GROUNDSTATION | -342              |
| NODE_ERROR_ROOTDIR       | -343              |
### MOST
| Error Type              | COSMOS Error Code |
|-------------------------|-------------------|
| MOST_USER_CANCELLED -35 | -351              |

###  Data
| Error Type                  | COSMOS Error Code |
|-----------------------------|-------------------|
| DATA_ERROR_ARCHIVE          | -361              |
| DATA_ERROR_SIZE_MISMATCH    | -362              |
| DATA_ERROR_CRC              | -363              |
| DATA_ERROR_FORMAT           | -364              |
| DATA_ERROR_RESOURCES_FOLDER | -365              |
| DATA_ERROR_NODES_FOLDER     | -366              |
| DATA_ERROR_ROOT_FOLDER      | -367              |

###  GIGE
| Error Type       | COSMOS Error Code |
|------------------|-------------------|
| GIGE_ERROR_NACK  | -371              |

###  CSSL
| Error Type                      | COSMOS Error Code |
|---------------------------------|-------------------|
| CSSL_ERROR_BASE                 | -380              |
| CSSL_ERROR_CHECKSUM             | -381              |
| CSSL_ERROR_READ                 | -382              |
| CSSL_ERROR_TIMEOUT              | -383              |
| CSSL_ERROR_EOT                  | -384              |
| CSSL_ERROR_SLIPIN               | -385              |
| CSSL_ERROR_SLIPOUT              | -386              |
| CSSL_ERROR_BUFFER_SIZE_EXCEEDED | -387              |
| CSSL_ERROR_BAD_ESCAPE           | -388              |
###  Serial
| Error Type                        | COSMOS Error Code |
|-----------------------------------|-------------------|
| SERIAL_ERROR_CHECKSUM             | -381              |
| SERIAL_ERROR_READ                 | -382              |
| SERIAL_ERROR_TIMEOUT              | -383              |
| SERIAL_ERROR_EOT                  | -384              |
| SERIAL_ERROR_SLIPIN               | -385              |
| SERIAL_ERROR_SLIPOUT              | -386              |
| SERIAL_ERROR_BUFFER_SIZE_EXCEEDED | -387              |
| SERIAL_ERROR_BAD_ESCAPE           | -388              |
| SERIAL_ERROR_OPEN                 | -389              |

###  IC9100
| Error Type              | COSMOS Error Code |
|-------------------------|-------------------|
| IC9100_ERROR_OPEN       | -391              |
| IC9100_ERROR_CLOSED     | -392              |
| IC9100_ERROR_OUTOFRANGE | -393              |
| IC9100_ERROR_WRITE      | -394              |
| IC9100_ERROR_NG         | -395              |
| IC9100_ERROR_READ       | -396              |
| IC9100_ERROR_ADDR       | -397              |

###  GPS GPS_ERROR_OPEN -401
| Error Type       | COSMOS Error Code |
|------------------|-------------------|
| GPS_ERROR_CLOSED | -402              |

###  OEMV
| Error Type          | COSMOS Error Code |
|---------------------|-------------------|
| OEMV_ERROR_OPEN     | -411              |
| OEMV_ERROR_CLOSED   | -412              |
| OEMV_ERROR_CRC      | -413              |
| OEMV_ERROR_RESPONSE | -414              |

###  PIC
| Error Type       | COSMOS Error Code |
|------------------|-------------------|
| PIC_ERROR_OPEN   | -421              |
| PIC_ERROR_CLOSED | -422              |
| PIC_ERROR_PORT   | -423              |
| PIC_ERROR_NACK   | -424              |
| PIC_ERROR_SIZE   | -425              |
| PIC_ERROR_ERR    | -426              |
| PIC_ERROR_TYPE   | -427              |
###  ASTRODEV
| Error Type                | COSMOS Error Code |
|---------------------------|-------------------|
| ASTRODEV_ERROR_HEADER_CS  | -431              |
| ASTRODEV_ERROR_SYNC0      | -432              |
| ASTRODEV_ERROR_NACK       | -433              |
| ASTRODEV_ERROR_PAYLOAD_CS | -434              |
| ASTRODEV_ERROR_SYNC1      | -435              |
| ASTRODEV_ERROR_HEADER     | -436              |
| ASTRODEV_ERROR_PAYLOAD    | -437              |

###  SUCHI
| Error Type         | COSMOS Error Code |
|--------------------|-------------------|
| SUCHI_ERROR_CLOSED | -441              |

###  VN100
| Error Type       | COSMOS Error Code |
|------------------|-------------------|
| VN100_ERROR_OPEN | -451              |
| VN100_ERROR_NACK | -452              |
| VN100_ERROR_SCAN | -453              |

###  ISC
| Error Type       | COSMOS Error Code |
|------------------|-------------------|
| ISC_ERROR_CLOSED | -461              |

###  Transfer
| Error Type               | COSMOS Error Code |
|--------------------------|-------------------|
| TRANSFER_ERROR_MATCH     | -471              |
| TRANSFER_ERROR_QUEUEFULL | -472              |
| TRANSFER_ERROR_INDEX     | -473              |
| TRANSFER_ERROR_NODE      | -474              |

###  Socket
| Error Type                 | COSMOS Error Code |
|----------------------------|-------------------|
| SOCKET_ERROR_CS            | -481              |
| SOCKET_ERROR_PROTOCOL      | -482              |
| SOCKET_READ_TIMEOUT        | -483              |
| SOCKET_ERROR_OPEN          | -484              |
| SOCKET_ERROR_OPEN_RECEIVE  | -485              |
| SOCKET_ERROR_OPEN_TRANSMIT | -486              |
| SOCKET_ERROR_OPEN_CONNECT  | -487              |
| SOCKET_ERROR_CLOSE         | -488              |

###  TRIMBLE
| Error Type       | COSMOS Error Code |
|------------------|-------------------|
| TRIMBLE_ERROR_CS | -491              |

###  JPLEPHEM
| Error Type                         | COSMOS Error Code |
|------------------------------------|-------------------|
| JPLEPHEM_ERROR_NOTFOUND            | -501              |
| JPLEPHEM_ERROR_INSUFFICIENT_MEMORY | -502              |
| JPLEPHEM_ERROR_OUTOFRANGE          | -503              |
| JPLEPHEM_ERROR_NUTATIONS           | -504              |
| JPLEPHEM_ERROR_LIBRATIONS          | -505              |

###  GEOMAG
| Error Type              | COSMOS Error Code |
|-------------------------|-------------------|
| GEOMAG_ERROR_NOTFOUND   | -511              |
| GEOMAG_ERROR_OUTOFRANGE | -512              |

###  PRKX2SU
| Error Type               | COSMOS Error Code |
|--------------------------|-------------------|
| PRKX2SU_ERROR_OPEN       | -521              |
| PRKX2SU_ERROR_CLOSED     | -522              |
| PRKX2SU_ERROR_OUTOFRANGE | -523              |
| PRKX2SU_ERROR_SEND       | -524              |

###  CONVERT
| Error Type        | COSMOS Error Code |
|-------------------|-------------------|
| CONVERT_ERROR_UTC | -531              |

###  CUBEADCS
| Error Type                   | COSMOS Error Code |
|------------------------------|-------------------|
| CUBEADCS_SERIALCOMM_RESPONSE | -601              |
| CUBEADCS_INVALID_RESPONSE    | -602              |
| CUBEADCS_NOT_CONNECTED       | -603              |
| CUBEADCS_SERIAL_PROTOCOL     | -604              |

###  CLYDEEPS
| Error Type              | COSMOS Error Code |
|-------------------------|-------------------|
| CLYDEEPS_NOT_CONNECTED  | -611              |

###  GENERAL
| Error Type                                  | COSMOS Error Code | Detail                                                                   |
|---------------------------------------------|-------------------|--------------------------------------------------------------------------|
| GENERAL_OK                                  | 0                 | everything is all right                                                  |
| GENERAL_ERROR_NOSIGNAL                      | -2001             | there's no free signal                                                   |
| GENERAL_ERROR_NOTSTARTED                    | -2002             | uninitialized error                                                      |
| GENERAL_ERROR_NULLPOINTER                   | -2003             | you gave a null pointer to the function                                  |
| GENERAL_ERROR_OOPS                          | -2004             | internal error, something's wrong                                        |
| GENERAL_ERROR_MEMORY                        | -2005             | there's no memory for more of something                                  |
| GENERAL_ERROR_OPEN                          | -2006             | file doesnt exist or you aren't good user                                |
| GENERAL_ERROR_CRC                           | -2007             | crc error                                                                |
| GENERAL_ERROR_OVERSIZE                      | -2008             | input was too large                                                      |
| GENERAL_ERROR_ZEROSIZE                      | -2009             | input cannot be zero size                                                |
| GENERAL_ERROR_UNIMPLEMENTED                 | -2010             | command is not implemented                                               |
| GENERAL_ERROR_EMPTY -2011 / usually indicat |                   | usually indicates that a buffer was empty                                |
| GENERAL_ERROR_EMPTY                         | -2011             | error that is not currently handled                                      |
| GENERAL_ERROR_UNHANDLED_ERR                 | -2012             | error that is not currently handled                                      |
| GENERAL_ERROR_UNDERSIZE                     | -2013             | packet is smaller than expected size                                     |
| GENERAL_ERROR_BAD_SIZE                      | -2014             | packet is an invalid size                                                |
| GENERAL_ERROR_TIMEOUT                       | -2015             | a timer expired                                                          |
| GENERAL_ERROR_INPUT                         | -2016             | invalid input was provided                                               |
| GENERAL_ERROR_OUTPUT                        | -2017             | output from a routine returned bad output, possibly related to bad input |
| GENERAL_ERROR_UNDEFINED                     | -2018             | undefined                                                                |
|                                             |                   |                                                                          |
