#pragma once

#define MTP_C_RST       "\033[0m"
#define MTP_C_BLK       "\033[30m"              /* Black */
#define MTP_C_RED       "\033[31m"              /* Red */
#define MTP_C_GRN       "\033[32m"              /* Green */
#define MTP_C_YLW       "\033[33m"              /* Yellow */
#define MTP_C_BLU       "\033[34m"              /* Blue */
#define MTP_C_MAG       "\033[35m"              /* Magenta */
#define MTP_C_CYA       "\033[36m"              /* Cyan */
#define MTP_C_WHT       "\033[37m"              /* White */
#define MTP_CB          "\033[1m"               /* Bold */
#define MTP_CB_BLK      MTP_CB MTP_C_BLK        /* Bold Black */
#define MTP_CB_RED      MTP_CB MTP_C_RED        /* Bold Red */
#define MTP_CB_GRN      MTP_CB MTP_C_GRN        /* Bold Green */
#define MTP_CB_YLW      MTP_CB MTP_C_YLW        /* Bold Yellow */
#define MTP_CB_BLU      MTP_CB MTP_C_BLU        /* Bold Blue */
#define MTP_CB_MAG      MTP_CB MTP_C_MAG        /* Bold Magenta */
#define MTP_CB_CYA      MTP_CB MTP_C_CYA        /* Bold Cyan */
#define MTP_CB_WHT      MTP_CB MTP_C_WHT        /* Bold White */

#define MTP_COLOR(c, x...) c x MTP_C_RST