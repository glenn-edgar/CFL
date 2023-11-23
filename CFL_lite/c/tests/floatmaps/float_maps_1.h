#ifndef __float_maps_1_H__
#define __float_maps_1_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t ecizpcahht[1];
static Event_data_CFL_t drpkbzbdiz[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t jrrjjfjeiz[] = { 
     {  10, drpkbzbdiz },
};
static const char *lgcoobqhzs = "start column";
static const unsigned short aobwnxxtfh[] = { 1,2};
const Enable_column_CFL_t oxfmzxplbu = { false, 2, aobwnxxtfh };
static const char *vnpvluoeiy = "terminating system";
static const char *mhdkysfuio = "configure reg maps";
static const dump_float_buffer_CFL_t qbtcbwcpiq = {0,32};
static const dump_float_buffer_CFL_t jfrbazcveq = {1,32};
static const clear_float_map_CFL_t xmsfufirrl = {0,10.140000,10,20};
static const clear_float_map_CFL_t iydckkjlks = {1,-10.950000,10,20};
static const dump_float_buffer_CFL_t tdhdxlptcz = {0,32};
static const dump_float_buffer_CFL_t xzmhucgvni = {1,32};
static const float dawozjpxbh[11] = {-5.1,-4.1,-3.1,-2.1,-1.1,0.1,1.1,2.1,3.1,4.1,5.1};
static const set_float_buffer_CFL_t yqhylyjzxj = {0,5,11,dawozjpxbh};
static const float rsastjresl[11] = {0.2,1.2,2.2,3.2,4.2,5.2,6.2,7.2,8.2,9.2,10.2};
static const set_float_buffer_CFL_t eejavryzpo = {1,10,11,rsastjresl};
static const dump_float_buffer_CFL_t vnclahaiux = {0,32};
static const dump_float_buffer_CFL_t umrghndsfs = {1,32};
static const float_map_copy_CFL_t hesvfrtzmb = {1,0,10,20,11};
static const dump_float_buffer_CFL_t tsqskumvos = {0,32};
static const dump_float_buffer_CFL_t tdtbakncxj = {1,32};
static const char *ishcenowzh = "s expression reg map";
static const clear_float_map_CFL_t arpbwkoetw = {0,0.000000,0,32};
static const float diamihotbr[5] = {1,2,3,4,5};
static const set_float_buffer_CFL_t pxjezezpvz = {0,5,5,diamihotbr};
static const float giytyizbjd[5] = {1,2,3,4,5};
static const set_float_buffer_CFL_t xeiklkszgk = {0,15,5,giytyizbjd};
static const dump_float_buffer_CFL_t znhogcdomv = {0,32};
const s_float_operator_CFL_t atkhublcuf[7] = {{2,{.operator_value = 0}},{0,{.float_value = 1.000000}},{0,{.float_value = 2.000000}},{0,{.float_value = 3.000000}},{0,{.float_value = 4.000000}},{0,{.float_value = 5.000000}},{3,{.end = 0}},};
const  s_float_definition_CFL_t cbzqmvzmys = {0,12,6,7,atkhublcuf};
static const s_float_expression_CFL_t rznzindazf = {0,3,&cbzqmvzmys};
const s_float_operator_CFL_t hlpecrfdrg[7] = {{2,{.operator_value = 0}},{1,{.buffer_position = 5}},{1,{.buffer_position = 6}},{1,{.buffer_position = 7}},{1,{.buffer_position = 8}},{1,{.buffer_position = 9}},{3,{.end = 0}},};
const  s_float_definition_CFL_t zxlivkseqj = {0,12,6,7,hlpecrfdrg};
static const s_float_expression_CFL_t wtppoxhdat = {0,4,&zxlivkseqj};
const s_float_operator_CFL_t arwzabpiuc[7] = {{2,{.operator_value = 2}},{0,{.float_value = 1.000000}},{0,{.float_value = 2.000000}},{0,{.float_value = 3.000000}},{0,{.float_value = 4.000000}},{0,{.float_value = 5.000000}},{3,{.end = 0}},};
const  s_float_definition_CFL_t cofqfolbms = {0,12,6,7,arwzabpiuc};
static const s_float_expression_CFL_t myffqxgdsg = {0,13,&cofqfolbms};
const s_float_operator_CFL_t xshfbzvvuh[7] = {{2,{.operator_value = 2}},{1,{.buffer_position = 15}},{1,{.buffer_position = 16}},{1,{.buffer_position = 17}},{1,{.buffer_position = 18}},{1,{.buffer_position = 19}},{3,{.end = 0}},};
const  s_float_definition_CFL_t pfivykldeq = {0,12,6,7,xshfbzvvuh};
static const s_float_expression_CFL_t fgyibbbqlm = {0,14,&pfivykldeq};
static const dump_float_buffer_CFL_t aoxhjnqytv = {0,32};
static const clear_float_map_CFL_t dqqbvisxdc = {0,0.000000,0,32};
const s_float_operator_CFL_t vhcudkelsa[4] = {{2,{.operator_value = 3}},{0,{.float_value = 10.500000}},{0,{.float_value = 5.000000}},{3,{.end = 0}},};
const  s_float_definition_CFL_t wnkbvdpbpo = {0,9,6,4,vhcudkelsa};
static const s_float_expression_CFL_t dtnkoazhjn = {0,0,&wnkbvdpbpo};
const s_float_operator_CFL_t jgotaidwnm[4] = {{2,{.operator_value = 1}},{0,{.float_value = 10.500000}},{0,{.float_value = 5.000000}},{3,{.end = 0}},};
const  s_float_definition_CFL_t wdzungiacz = {0,9,6,4,jgotaidwnm};
static const s_float_expression_CFL_t cteqzeqjaf = {0,1,&wdzungiacz};
const s_float_operator_CFL_t pdseiucbml[4] = {{2,{.operator_value = 4}},{0,{.float_value = 10.500000}},{0,{.float_value = 1.000000}},{3,{.end = 0}},};
const  s_float_definition_CFL_t vcmlfosgsp = {0,9,6,4,pdseiucbml};
static const s_float_expression_CFL_t vqzmlxyrwv = {0,2,&vcmlfosgsp};
const s_float_operator_CFL_t vtifxcetxt[4] = {{2,{.operator_value = 5}},{0,{.float_value = 2.000000}},{0,{.float_value = 3.000000}},{3,{.end = 0}},};
const  s_float_definition_CFL_t idltxmewve = {0,9,6,4,vtifxcetxt};
static const s_float_expression_CFL_t uysjwwrmtx = {0,3,&idltxmewve};
const s_float_operator_CFL_t lqzwfqtzzv[14] = {{2,{.operator_value = 2}},{2,{.operator_value = 0}},{0,{.float_value = 2.000000}},{2,{.operator_value = 5}},{0,{.float_value = 3.000000}},{0,{.float_value = 2.000000}},{3,{.end = 0}},{3,{.end = 0}},{2,{.operator_value = 0}},{0,{.float_value = 2.000000}},{0,{.float_value = 3.000000}},{3,{.end = 0}},{0,{.float_value = 4.000000}},{3,{.end = 0}},};
const  s_float_definition_CFL_t nhiqmkojcq = {0,10,9,14,lqzwfqtzzv};
static const s_float_expression_CFL_t inwjkkzswi = {0,4,&nhiqmkojcq};
static const dump_float_buffer_CFL_t nvehoibgcz = {0,32};
static const clear_float_map_CFL_t ovmuqviyny = {0,0.000000,0,32};
const s_float_operator_CFL_t xsbqgcpaqd[5] = {{2,{.operator_value = 6}},{2,{.operator_value = 7}},{0,{.float_value = 2.000000}},{3,{.end = 0}},{3,{.end = 0}},};
const  s_float_definition_CFL_t arkzvtqhhk = {0,8,7,5,xsbqgcpaqd};
static const s_float_expression_CFL_t apmtsixmdj = {0,0,&arkzvtqhhk};
const s_float_operator_CFL_t xjwadrdefy[5] = {{2,{.operator_value = 8}},{2,{.operator_value = 9}},{0,{.float_value = 2.300000}},{3,{.end = 0}},{3,{.end = 0}},};
const  s_float_definition_CFL_t vpcbiecyoz = {0,8,7,5,xjwadrdefy};
static const s_float_expression_CFL_t ierdexqzdm = {0,1,&vpcbiecyoz};
const s_float_operator_CFL_t xoyyyvapbl[5] = {{2,{.operator_value = 29}},{2,{.operator_value = 30}},{0,{.float_value = 45.000000}},{3,{.end = 0}},{3,{.end = 0}},};
const  s_float_definition_CFL_t wjiovdqmgt = {0,8,7,5,xoyyyvapbl};
static const s_float_expression_CFL_t vvdvfyenpk = {0,2,&wjiovdqmgt};
const s_float_operator_CFL_t ftzpnparku[9] = {{2,{.operator_value = 29}},{2,{.operator_value = 13}},{2,{.operator_value = 10}},{2,{.operator_value = 30}},{0,{.float_value = 45.000000}},{3,{.end = 0}},{3,{.end = 0}},{3,{.end = 0}},{3,{.end = 0}},};
const  s_float_definition_CFL_t xhpyotqbse = {0,8,9,9,ftzpnparku};
static const s_float_expression_CFL_t frubhzayxv = {0,3,&xhpyotqbse};
const s_float_operator_CFL_t yirphiegxs[9] = {{2,{.operator_value = 29}},{2,{.operator_value = 14}},{2,{.operator_value = 11}},{2,{.operator_value = 30}},{0,{.float_value = 45.000000}},{3,{.end = 0}},{3,{.end = 0}},{3,{.end = 0}},{3,{.end = 0}},};
const  s_float_definition_CFL_t kfjkypmaag = {0,8,9,9,yirphiegxs};
static const s_float_expression_CFL_t gqjuyrwqhq = {0,4,&kfjkypmaag};
const s_float_operator_CFL_t nsshzvgrjx[9] = {{2,{.operator_value = 29}},{2,{.operator_value = 15}},{2,{.operator_value = 12}},{2,{.operator_value = 30}},{0,{.float_value = 45.000000}},{3,{.end = 0}},{3,{.end = 0}},{3,{.end = 0}},{3,{.end = 0}},};
const  s_float_definition_CFL_t zytrjzbxdr = {0,8,9,9,nsshzvgrjx};
static const s_float_expression_CFL_t yqgpmvfjan = {0,5,&zytrjzbxdr};
const s_float_operator_CFL_t ghtlofvgkj[5] = {{2,{.operator_value = 19}},{2,{.operator_value = 16}},{0,{.float_value = 2.300000}},{3,{.end = 0}},{3,{.end = 0}},};
const  s_float_definition_CFL_t hmjejqrnsp = {0,8,7,5,ghtlofvgkj};
static const s_float_expression_CFL_t nimrhoaiaf = {0,6,&hmjejqrnsp};
const s_float_operator_CFL_t ignrgxnmqc[5] = {{2,{.operator_value = 20}},{2,{.operator_value = 17}},{0,{.float_value = 2.300000}},{3,{.end = 0}},{3,{.end = 0}},};
const  s_float_definition_CFL_t mumfrrtnwq = {0,8,7,5,ignrgxnmqc};
static const s_float_expression_CFL_t rzgplyhbbh = {0,7,&mumfrrtnwq};
const s_float_operator_CFL_t giqtrwulqz[5] = {{2,{.operator_value = 21}},{2,{.operator_value = 18}},{0,{.float_value = 2.300000}},{3,{.end = 0}},{3,{.end = 0}},};
const  s_float_definition_CFL_t ebwghmzltc = {0,8,7,5,giqtrwulqz};
static const s_float_expression_CFL_t qdxfizaaxn = {0,8,&ebwghmzltc};
const s_float_operator_CFL_t apuuibomqe[3] = {{2,{.operator_value = 22}},{0,{.float_value = 2.300000}},{3,{.end = 0}},};
const  s_float_definition_CFL_t ohgifetyuk = {0,8,6,3,apuuibomqe};
static const s_float_expression_CFL_t lpyglajbml = {0,9,&ohgifetyuk};
const s_float_operator_CFL_t wigfcocvvi[2] = {{2,{.operator_value = 28}},{3,{.end = 0}},};
const  s_float_definition_CFL_t qdnwkcsckf = {0,7,6,2,wigfcocvvi};
static const s_float_expression_CFL_t ccybbezugt = {0,10,&qdnwkcsckf};
const s_float_operator_CFL_t zownwoitjw[3] = {{2,{.operator_value = 23}},{0,{.float_value = -2.300000}},{3,{.end = 0}},};
const  s_float_definition_CFL_t oqxffvlpnq = {0,8,6,3,zownwoitjw};
static const s_float_expression_CFL_t kqyjheqdzf = {0,11,&oqxffvlpnq};
const s_float_operator_CFL_t juvrjzkyvo[3] = {{2,{.operator_value = 23}},{0,{.float_value = 2.300000}},{3,{.end = 0}},};
const  s_float_definition_CFL_t ghjnbragse = {0,8,6,3,juvrjzkyvo};
static const s_float_expression_CFL_t envayfibgc = {0,12,&ghjnbragse};
const s_float_operator_CFL_t bfjnouwdpw[3] = {{2,{.operator_value = 24}},{0,{.float_value = 2.300000}},{3,{.end = 0}},};
const  s_float_definition_CFL_t wumtelwozo = {0,8,6,3,bfjnouwdpw};
static const s_float_expression_CFL_t eyboecehfe = {0,13,&wumtelwozo};
const s_float_operator_CFL_t gvesmfozpd[3] = {{2,{.operator_value = 24}},{0,{.float_value = -2.300000}},{3,{.end = 0}},};
const  s_float_definition_CFL_t tdhvuihybk = {0,8,6,3,gvesmfozpd};
static const s_float_expression_CFL_t ehqyaukbta = {0,14,&tdhvuihybk};
const s_float_operator_CFL_t damzotfdtv[3] = {{2,{.operator_value = 24}},{0,{.float_value = 2.300000}},{3,{.end = 0}},};
const  s_float_definition_CFL_t pxrbrqyqrs = {0,8,6,3,damzotfdtv};
static const s_float_expression_CFL_t asgbujkaiw = {0,15,&pxrbrqyqrs};
const s_float_operator_CFL_t nujqrgwxle[3] = {{2,{.operator_value = 24}},{0,{.float_value = -2.300000}},{3,{.end = 0}},};
const  s_float_definition_CFL_t ujyhmvxdat = {0,8,6,3,nujqrgwxle};
static const s_float_expression_CFL_t cbpmniwrkk = {0,16,&ujyhmvxdat};
const s_float_operator_CFL_t evbupynicw[3] = {{2,{.operator_value = 24}},{0,{.float_value = 2.300000}},{3,{.end = 0}},};
const  s_float_definition_CFL_t rmiwgthojk = {0,8,6,3,evbupynicw};
static const s_float_expression_CFL_t kgtwzdjlhh = {0,17,&rmiwgthojk};
const s_float_operator_CFL_t soupknerly[3] = {{2,{.operator_value = 24}},{0,{.float_value = -2.300000}},{3,{.end = 0}},};
const  s_float_definition_CFL_t aserkwhuar = {0,8,6,3,soupknerly};
static const s_float_expression_CFL_t zmwzijjlhd = {0,18,&aserkwhuar};
const s_float_operator_CFL_t nkktonobbb[3] = {{2,{.operator_value = 27}},{0,{.float_value = 2.300000}},{3,{.end = 0}},};
const  s_float_definition_CFL_t xpckzqzgcp = {0,8,6,3,nkktonobbb};
static const s_float_expression_CFL_t yxjixfftem = {0,19,&xpckzqzgcp};
const s_float_operator_CFL_t mnpyecvnox[3] = {{2,{.operator_value = 27}},{0,{.float_value = -2.300000}},{3,{.end = 0}},};
const  s_float_definition_CFL_t ufcundyrbv = {0,8,6,3,mnpyecvnox};
static const s_float_expression_CFL_t lcwomvilta = {0,20,&ufcundyrbv};
static const dump_float_buffer_CFL_t sfletqhhsk = {0,32};


//----------RAM data structures for columns ----

unsigned ihexaffpgl[3];
Watch_dog_struct_CFL_t * vsiaondino[3];
unsigned char mfxbkjjwsg[3];
unsigned char yxywscevnb[3];
void* ymufjcoufn[3];
/*
------------------------ ROM data structures for columns --------------------------
typedef struct Column_ROM_CFL_t
{
  short queue_number;
  bool auto_start;
  unsigned short id;
  unsigned short number;
  unsigned short start;
  short start_state;
  short end_state;
  
} Column_ROM_CFL_t;

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/


//----------ROM data structures for columns ----

static const Column_ROM_CFL_t nuorinclal[] = {
  { -1,true, 0, 4, 0, -1, -1 },
  { -1,false, 1, 15, 4, -1, -1 },
  { -1,false, 2, 41, 19, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char jpzyyhauet[60];


  /* 
  ------------------------ Column element Flash structure --------------------------
     typedef struct Column_element_CFL_t {
        Column_function_CFL_t column_function;
        void *aux_fn;
        void *params
     } Column_element_CFL_t;

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

*/

  

//----------Column elements Flash structures----

static const Column_element_CFL_t zpvzslzegm[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&lgcoobqhzs},
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&oxfmzxplbu},
    {one_shot_handler_CFL,log_message_CFL,(void *)&vnpvluoeiy},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&mhdkysfuio},
    {one_shot_handler_CFL,dump_float_buffer_CFL,(void *)&qbtcbwcpiq},
    {one_shot_handler_CFL,dump_float_buffer_CFL,(void *)&jfrbazcveq},
    {one_shot_handler_CFL,clear_float_map_CFL,(void *)&xmsfufirrl},
    {one_shot_handler_CFL,clear_float_map_CFL,(void *)&iydckkjlks},
    {one_shot_handler_CFL,dump_float_buffer_CFL,(void *)&tdhdxlptcz},
    {one_shot_handler_CFL,dump_float_buffer_CFL,(void *)&xzmhucgvni},
    {one_shot_handler_CFL,set_float_buffer_CFL,(void *)&yqhylyjzxj},
    {one_shot_handler_CFL,set_float_buffer_CFL,(void *)&eejavryzpo},
    {one_shot_handler_CFL,dump_float_buffer_CFL,(void *)&vnclahaiux},
    {one_shot_handler_CFL,dump_float_buffer_CFL,(void *)&umrghndsfs},
    {one_shot_handler_CFL,float_map_copy_CFL,(void *)&hesvfrtzmb},
    {one_shot_handler_CFL,dump_float_buffer_CFL,(void *)&tsqskumvos},
    {one_shot_handler_CFL,dump_float_buffer_CFL,(void *)&tdtbakncxj},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ishcenowzh},
    {one_shot_handler_CFL,clear_float_map_CFL,(void *)&arpbwkoetw},
    {one_shot_handler_CFL,set_float_buffer_CFL,(void *)&pxjezezpvz},
    {one_shot_handler_CFL,set_float_buffer_CFL,(void *)&xeiklkszgk},
    {one_shot_handler_CFL,dump_float_buffer_CFL,(void *)&znhogcdomv},
    {one_shot_handler_CFL,float_map_s_expr_CFL,(void *)&rznzindazf},
    {one_shot_handler_CFL,float_map_s_expr_CFL,(void *)&wtppoxhdat},
    {one_shot_handler_CFL,float_map_s_expr_CFL,(void *)&myffqxgdsg},
    {one_shot_handler_CFL,float_map_s_expr_CFL,(void *)&fgyibbbqlm},
    {one_shot_handler_CFL,dump_float_buffer_CFL,(void *)&aoxhjnqytv},
    {one_shot_handler_CFL,clear_float_map_CFL,(void *)&dqqbvisxdc},
    {one_shot_handler_CFL,float_map_s_expr_CFL,(void *)&dtnkoazhjn},
    {one_shot_handler_CFL,float_map_s_expr_CFL,(void *)&cteqzeqjaf},
    {one_shot_handler_CFL,float_map_s_expr_CFL,(void *)&vqzmlxyrwv},
    {one_shot_handler_CFL,float_map_s_expr_CFL,(void *)&uysjwwrmtx},
    {one_shot_handler_CFL,float_map_s_expr_CFL,(void *)&inwjkkzswi},
    {one_shot_handler_CFL,dump_float_buffer_CFL,(void *)&nvehoibgcz},
    {one_shot_handler_CFL,clear_float_map_CFL,(void *)&ovmuqviyny},
    {one_shot_handler_CFL,float_map_s_expr_CFL,(void *)&apmtsixmdj},
    {one_shot_handler_CFL,float_map_s_expr_CFL,(void *)&ierdexqzdm},
    {one_shot_handler_CFL,float_map_s_expr_CFL,(void *)&vvdvfyenpk},
    {one_shot_handler_CFL,float_map_s_expr_CFL,(void *)&frubhzayxv},
    {one_shot_handler_CFL,float_map_s_expr_CFL,(void *)&gqjuyrwqhq},
    {one_shot_handler_CFL,float_map_s_expr_CFL,(void *)&yqgpmvfjan},
    {one_shot_handler_CFL,float_map_s_expr_CFL,(void *)&nimrhoaiaf},
    {one_shot_handler_CFL,float_map_s_expr_CFL,(void *)&rzgplyhbbh},
    {one_shot_handler_CFL,float_map_s_expr_CFL,(void *)&qdxfizaaxn},
    {one_shot_handler_CFL,float_map_s_expr_CFL,(void *)&lpyglajbml},
    {one_shot_handler_CFL,float_map_s_expr_CFL,(void *)&ccybbezugt},
    {one_shot_handler_CFL,float_map_s_expr_CFL,(void *)&kqyjheqdzf},
    {one_shot_handler_CFL,float_map_s_expr_CFL,(void *)&envayfibgc},
    {one_shot_handler_CFL,float_map_s_expr_CFL,(void *)&eyboecehfe},
    {one_shot_handler_CFL,float_map_s_expr_CFL,(void *)&ehqyaukbta},
    {one_shot_handler_CFL,float_map_s_expr_CFL,(void *)&asgbujkaiw},
    {one_shot_handler_CFL,float_map_s_expr_CFL,(void *)&cbpmniwrkk},
    {one_shot_handler_CFL,float_map_s_expr_CFL,(void *)&kgtwzdjlhh},
    {one_shot_handler_CFL,float_map_s_expr_CFL,(void *)&zmwzijjlhd},
    {one_shot_handler_CFL,float_map_s_expr_CFL,(void *)&yxjixfftem},
    {one_shot_handler_CFL,float_map_s_expr_CFL,(void *)&lcwomvilta},
    {one_shot_handler_CFL,dump_float_buffer_CFL,(void *)&sfletqhhsk},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
};
Bitmap_CFL hucvhaqxyx[0];
Registermap_CFL_t zadfafvxjg[0];
static float rbmcsuuonm[32]= {-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0,-1.0};
static float gykhoohhpg[32]= {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
Floatmap_CFL_t wpisqwcafa[2] = {
 {32, &rbmcsuuonm[0]},
 {32, &gykhoohhpg[0]},
};
const Sm_control_ROM_CFL_t vkfqcaboli[0];
Sm_control_RAM_CFL_t vpfgblasvj[0];


static Time_control_CFL_t rzdxkxvhdo;




static Engine_control_CFL_t ghegclylxa;


/* remaining allocate heap size */

static unsigned flubacutec;


/* current heap pointer */

static char* pwjrpxzhyh;


/* heap block area */

static CS_MEMORY_CONTROL ijpdfqiydu;


    
    


const struct Handle_CFL_t enpkfoanek =
{

  .queue_number = 1,
  .queue_rom = jrrjjfjeiz,
  .queue_ram = ecizpcahht,

  .column_elements_flags =jpzyyhauet,
  .column_elements_ROM = zpvzslzegm,

  .watch_dog_struct = vsiaondino,
  .watch_dog_count  = ihexaffpgl,
   
   
  .column_flags = mfxbkjjwsg,
  .column_local_data = ymufjcoufn,
  .column_state = yxywscevnb,
  .number_of_columns = 3,
  .column_rom_data = nuorinclal,

  
  
  
  .time_control = &rzdxkxvhdo,
  .engine_control =&ghegclylxa,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 10000,
  .remaining_heap_size = &flubacutec,
  .current_heap_location = &pwjrpxzhyh,
  .private_heap   = &ijpdfqiydu,
  .private_heap_size =   1000,
  .number_of_sm      = 0,
  .sm_rom     =  vkfqcaboli,
  .sm_ram     = vpfgblasvj,
  .number_of_bitmaps = 0,
  .bitmaps = hucvhaqxyx,
  .number_of_registermaps = 0,
  .registermaps = zadfafvxjg,
  .number_of_floatmaps = 2,
  .floatmaps = wpisqwcafa,
} ;

const Handle_CFL_t*  float_map_1_handle(){
    return &enpkfoanek;
}
   

#ifdef __cplusplus
}
#endif

#endif
