
#include "root.h"
#include "lib/layer.h"

typedef event_list_t e;
typedef uvar h;
typedef void z;
typedef layer_t t;
typedef char s;

#define g get_events
#define d layer_dispose
#define r layer_draw
#define f video_flip
#define c video_clear
#define o video_clear_colour
#define j layer_canvas_set_pixel
#define a layer_canvas_flip
#define l layer_set_colour
#define m _UI64_MAX
#define _ video_width
#define k video_height
#define u layer_set_canvas
#define p layer_init
#define q new_layer
#define x for
#define b return
#define w main

h w(z){t v;h y[2]={(q(&v),'?'[(h\
*)&v]++)};u(&v,_()>>2,k()>>2),p(\
&v);e i;x(h*n=&i;!257[n];){o(++0\
[y]*(m/256),0,-1,-1);l(&v,-1,++1\
[y]*(m>>'\b'),0);r((c(),&v)),f()\
;*y=(s)*y;1[y]=(s)++1[y];g(&\
i);258[n]?j(&v,259[n]>>2,260[n]>\
>(s)2,-1ul),a(&v):0;}b d(&v),0;}\
