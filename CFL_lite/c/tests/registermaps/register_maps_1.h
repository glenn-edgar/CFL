#ifndef __register_maps_1_H__
#define __register_maps_1_H__

#ifdef __cplusplus
extern "C" {
#endif
#include <stdbool.h>   


#include "run_time_code_CFL.h"


//nuser defined events 



//----------RAM data structures for event queues ----

static Event_control_RAM_CFL_t fjflhhxadz[1];
static Event_data_CFL_t lditnovqqw[10];


//------  ROM data structures for event queues ----

static const Event_control_ROM_CFL_t yhjbvilkwe[] = { 
     {  10, lditnovqqw },
};
static const char *weinumltrh = "start column";
static const unsigned short jnstbgrqur[] = { 1,2,3,4,5};
const Enable_column_CFL_t etwmdqjecv = { true, 5, jnstbgrqur };


unsigned  gxdessdmhl;
const While_time_control_ROM_CFL_t jqodzxshsq = { 10000,&gxdessdmhl };



static While_control_RAM_CFL_t yhdvpcoxrz_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t pmokfduqjd_rom = { 0 ,true, &jqodzxshsq,&yhdvpcoxrz_ram,null_function};

    
static const char *kiicbnrssc = "terminating system";
static const char *xsmywqifno = "configure reg maps";
static const dump_register_buffer_CFL_t tkrygcupui = {0,32};
static const dump_register_buffer_CFL_t joixkkssxv = {1,32};
static const clear_register_map_CFL_t ktfwieejbv = {0,10,10,20};
static const clear_register_map_CFL_t evvzpprwzk = {1,-10,10,20};
static const dump_register_buffer_CFL_t glaspwvwik = {0,32};
static const dump_register_buffer_CFL_t shcfszzzhg = {1,32};
static const clear_register_map_CFL_t macijfcwrj = {0,10,0,32};
static const clear_register_map_CFL_t tjccsfptoz = {1,-10,0,32};
static const dump_register_buffer_CFL_t aisjaoyrst = {0,32};
static const dump_register_buffer_CFL_t jfvwcukzrr = {1,32};
static const clear_register_map_CFL_t flijoosjke = {0,0,0,32};
static const clear_register_map_CFL_t jebcseripn = {1,0,0,32};
static const dump_register_buffer_CFL_t whmuartfcj = {0,32};
static const dump_register_buffer_CFL_t uuxwugpwuy = {1,32};
static const int16_t zmdqgjsspi[11] = {-5,-4,-3,-2,-1,0,1,2,3,4,5};
static const set_register_buffer_CFL_t lrtpyosodj = {0,5,11,zmdqgjsspi};
static const int16_t gujyltcuyb[11] = {0,1,2,3,4,5,6,7,8,9,10};
static const set_register_buffer_CFL_t irmzxysvec = {1,10,11,gujyltcuyb};
static const dump_register_buffer_CFL_t frgnerypyr = {0,32};
static const dump_register_buffer_CFL_t arlibjhmif = {1,32};
static const register_map_copy_CFL_t hvrhtlntnj = {1,0,10,20,11};
static const dump_register_buffer_CFL_t jarauhgxzd = {0,32};
static const char *xjungcdmzg = "s expression reg map";
static const clear_register_map_CFL_t eafmliujbw = {0,0,0,32};
static const int16_t xgybhtbuup[5] = {0,1,2,3,4};
static const set_register_buffer_CFL_t ocgwacynkw = {0,0,5,xgybhtbuup};
static const dump_register_buffer_CFL_t jtxhfipyxj = {0,32};
const s_register_operator_CFL_t betujipkyz[6] = {{2,{.operator_value = 2}},{1,{.buffer_position = 1}},{1,{.buffer_position = 2}},{1,{.buffer_position = 3}},{1,{.buffer_position = 4}},{3,{.end = 0}},};
const  s_register_definition_CFL_t ddvdpvjmbc = {0,11,6,6,betujipkyz};
static const s_reg_expression_CFL_t jvghynhpeg = {0,0,&ddvdpvjmbc};
static const dump_register_buffer_CFL_t fvsrgisrax = {0,32};
const s_register_operator_CFL_t hzlesvaznj[6] = {{2,{.operator_value = 2}},{1,{.buffer_position = 1}},{0,{.value = 15}},{1,{.buffer_position = 3}},{0,{.value = 30}},{3,{.end = 0}},};
const  s_register_definition_CFL_t tpwfpomdgh = {0,11,6,6,hzlesvaznj};
static const s_reg_expression_CFL_t pgvkqmgpbx = {0,0,&tpwfpomdgh};
static const dump_register_buffer_CFL_t wezmslxvgh = {0,32};
const s_register_operator_CFL_t qfvycurzxy[6] = {{2,{.operator_value = 0}},{1,{.buffer_position = 1}},{1,{.buffer_position = 2}},{1,{.buffer_position = 3}},{1,{.buffer_position = 4}},{3,{.end = 0}},};
const  s_register_definition_CFL_t kldrgekrvw = {0,11,6,6,qfvycurzxy};
static const s_reg_expression_CFL_t utkxyhxlas = {0,0,&kldrgekrvw};
static const dump_register_buffer_CFL_t jtvqwmriet = {0,32};
static const int16_t zksiemdyyu[2] = {5,2};
static const set_register_buffer_CFL_t wygnckbjlg = {0,1,2,zksiemdyyu};
static const dump_register_buffer_CFL_t wugceogqdn = {0,32};
const s_register_operator_CFL_t ngfsgwhkba[4] = {{2,{.operator_value = 3}},{1,{.buffer_position = 1}},{1,{.buffer_position = 2}},{3,{.end = 0}},};
const  s_register_definition_CFL_t pdztuoecoi = {0,9,6,4,ngfsgwhkba};
static const s_reg_expression_CFL_t ujuoguctot = {0,0,&pdztuoecoi};
static const dump_register_buffer_CFL_t vvmmwwicol = {0,32};
const s_register_operator_CFL_t oqklbbhqxx[4] = {{2,{.operator_value = 4}},{1,{.buffer_position = 1}},{1,{.buffer_position = 2}},{3,{.end = 0}},};
const  s_register_definition_CFL_t xitjsysmng = {0,9,6,4,oqklbbhqxx};
static const s_reg_expression_CFL_t egsuqafrey = {0,0,&xitjsysmng};
static const dump_register_buffer_CFL_t rthynndwva = {0,32};
const s_register_operator_CFL_t hyhrdhnber[4] = {{2,{.operator_value = 1}},{1,{.buffer_position = 1}},{1,{.buffer_position = 2}},{3,{.end = 0}},};
const  s_register_definition_CFL_t weojuascpq = {0,9,6,4,hyhrdhnber};
static const s_reg_expression_CFL_t zhjwtkdhyl = {0,0,&weojuascpq};
static const dump_register_buffer_CFL_t lgtupntkzd = {0,32};
const s_register_operator_CFL_t nhojzscbao[4] = {{2,{.operator_value = 5}},{1,{.buffer_position = 1}},{0,{.value = 1}},{3,{.end = 0}},};
const  s_register_definition_CFL_t dgdjimsgbw = {0,9,6,4,nhojzscbao};
static const s_reg_expression_CFL_t pdzpqfhbea = {0,0,&dgdjimsgbw};
static const dump_register_buffer_CFL_t fedvydthst = {0,32};
const s_register_operator_CFL_t ydhmovjpuw[4] = {{2,{.operator_value = 5}},{1,{.buffer_position = 1}},{0,{.value = -1}},{3,{.end = 0}},};
const  s_register_definition_CFL_t wpbtcgjprk = {0,9,6,4,ydhmovjpuw};
static const s_reg_expression_CFL_t ooqorgugbl = {0,0,&wpbtcgjprk};
static const dump_register_buffer_CFL_t bgcpttchiv = {0,32};
const s_register_operator_CFL_t ghzsrbppex[4] = {{2,{.operator_value = 6}},{1,{.buffer_position = 1}},{1,{.buffer_position = 2}},{3,{.end = 0}},};
const  s_register_definition_CFL_t obikceyemm = {0,9,6,4,ghzsrbppex};
static const s_reg_expression_CFL_t nvodgerqjn = {0,0,&obikceyemm};
static const dump_register_buffer_CFL_t bslcnnuloq = {0,32};
const s_register_operator_CFL_t jwlctgkhvl[4] = {{2,{.operator_value = 7}},{1,{.buffer_position = 1}},{1,{.buffer_position = 2}},{3,{.end = 0}},};
const  s_register_definition_CFL_t hlnlqoepmm = {0,9,6,4,jwlctgkhvl};
static const s_reg_expression_CFL_t gzcbpgqers = {0,0,&hlnlqoepmm};
static const dump_register_buffer_CFL_t bjliiqraok = {0,32};
const s_register_operator_CFL_t vhfoaikzgf[4] = {{2,{.operator_value = 8}},{1,{.buffer_position = 1}},{1,{.buffer_position = 2}},{3,{.end = 0}},};
const  s_register_definition_CFL_t ixqbsbedzb = {0,9,6,4,vhfoaikzgf};
static const s_reg_expression_CFL_t hpochygash = {0,0,&ixqbsbedzb};
static const dump_register_buffer_CFL_t pibhjtwuxf = {0,32};
const s_register_operator_CFL_t wyleyraayx[4] = {{2,{.operator_value = 9}},{1,{.buffer_position = 1}},{1,{.buffer_position = 2}},{3,{.end = 0}},};
const  s_register_definition_CFL_t ayhnidilfb = {0,9,6,4,wyleyraayx};
static const s_reg_expression_CFL_t fpsdpislro = {0,0,&ayhnidilfb};
static const dump_register_buffer_CFL_t atddypqrfo = {0,32};
const s_register_operator_CFL_t vhmjwzbshk[4] = {{2,{.operator_value = 10}},{1,{.buffer_position = 1}},{1,{.buffer_position = 2}},{3,{.end = 0}},};
const  s_register_definition_CFL_t apkquwtpde = {0,9,6,4,vhmjwzbshk};
static const s_reg_expression_CFL_t taplowmgby = {0,0,&apkquwtpde};
static const dump_register_buffer_CFL_t xctfclljib = {0,32};
const s_register_operator_CFL_t vtvfghhplz[4] = {{2,{.operator_value = 11}},{1,{.buffer_position = 1}},{1,{.buffer_position = 2}},{3,{.end = 0}},};
const  s_register_definition_CFL_t nqkkycvipp = {0,9,6,4,vtvfghhplz};
static const s_reg_expression_CFL_t wgbqdquask = {0,0,&nqkkycvipp};
static const dump_register_buffer_CFL_t wdunxjgnta = {0,32};
const s_register_operator_CFL_t hdgnxjuurb[4] = {{2,{.operator_value = 14}},{0,{.value = 5}},{0,{.value = 5}},{3,{.end = 0}},};
const  s_register_definition_CFL_t vkgjejulcy = {0,9,6,4,hdgnxjuurb};
static const s_reg_expression_CFL_t vucrghujgn = {0,0,&vkgjejulcy};
static const dump_register_buffer_CFL_t qtrxmarflo = {0,32};
const s_register_operator_CFL_t xlktanwnfy[4] = {{2,{.operator_value = 14}},{0,{.value = 5}},{0,{.value = 4}},{3,{.end = 0}},};
const  s_register_definition_CFL_t rnzbhbmjlk = {0,9,6,4,xlktanwnfy};
static const s_reg_expression_CFL_t tqjvgnurfr = {0,0,&rnzbhbmjlk};
static const dump_register_buffer_CFL_t rfmvqjlrvt = {0,32};
const s_register_operator_CFL_t avjywkpfun[4] = {{2,{.operator_value = 15}},{0,{.value = 5}},{0,{.value = 5}},{3,{.end = 0}},};
const  s_register_definition_CFL_t vestvycykt = {0,9,6,4,avjywkpfun};
static const s_reg_expression_CFL_t jfkydpuzrx = {0,0,&vestvycykt};
static const dump_register_buffer_CFL_t vavqfwdqdy = {0,32};
const s_register_operator_CFL_t mjsxrnsadc[4] = {{2,{.operator_value = 15}},{0,{.value = 5}},{0,{.value = 4}},{3,{.end = 0}},};
const  s_register_definition_CFL_t qqklzsfzdn = {0,9,6,4,mjsxrnsadc};
static const s_reg_expression_CFL_t fjenmuxfes = {0,0,&qqklzsfzdn};
static const dump_register_buffer_CFL_t hnznsdciis = {0,32};
const s_register_operator_CFL_t ytzxprumuk[4] = {{2,{.operator_value = 16}},{0,{.value = 5}},{0,{.value = 5}},{3,{.end = 0}},};
const  s_register_definition_CFL_t yifphdiuqg = {0,9,6,4,ytzxprumuk};
static const s_reg_expression_CFL_t xksdpejhfl = {0,0,&yifphdiuqg};
static const dump_register_buffer_CFL_t zgwybznhqc = {0,32};
const s_register_operator_CFL_t jzreovejbg[4] = {{2,{.operator_value = 16}},{0,{.value = 5}},{0,{.value = 4}},{3,{.end = 0}},};
const  s_register_definition_CFL_t yirsugsysb = {0,9,6,4,jzreovejbg};
static const s_reg_expression_CFL_t wrwkbfpobs = {0,0,&yirsugsysb};
static const dump_register_buffer_CFL_t hvwhqyjbxy = {0,32};
const s_register_operator_CFL_t duhtfgnxoz[4] = {{2,{.operator_value = 17}},{0,{.value = 5}},{0,{.value = 5}},{3,{.end = 0}},};
const  s_register_definition_CFL_t juilbfvdmb = {0,9,6,4,duhtfgnxoz};
static const s_reg_expression_CFL_t dxpcydncgv = {0,0,&juilbfvdmb};
static const dump_register_buffer_CFL_t qzeeznnslp = {0,32};
const s_register_operator_CFL_t piyowuerap[4] = {{2,{.operator_value = 17}},{0,{.value = 4}},{0,{.value = 5}},{3,{.end = 0}},};
const  s_register_definition_CFL_t ndwpywsima = {0,9,6,4,piyowuerap};
static const s_reg_expression_CFL_t tvldqnhnub = {0,0,&ndwpywsima};
static const dump_register_buffer_CFL_t aqppwgsbvp = {0,32};
const s_register_operator_CFL_t olksuwmwdj[4] = {{2,{.operator_value = 18}},{0,{.value = 5}},{0,{.value = 5}},{3,{.end = 0}},};
const  s_register_definition_CFL_t gzayeuqiym = {0,9,6,4,olksuwmwdj};
static const s_reg_expression_CFL_t oouyzlyzas = {0,0,&gzayeuqiym};
static const dump_register_buffer_CFL_t kgkjdhpwwj = {0,32};
const s_register_operator_CFL_t fwyholzepp[4] = {{2,{.operator_value = 18}},{0,{.value = 4}},{0,{.value = 5}},{3,{.end = 0}},};
const  s_register_definition_CFL_t ttehjtxzpv = {0,9,6,4,fwyholzepp};
static const s_reg_expression_CFL_t njvhyudydb = {0,0,&ttehjtxzpv};
static const dump_register_buffer_CFL_t butuchtdnb = {0,32};
static const char *aesjowtruj = "terminating s expression reg map";
static const char *dpqxvzxahq = "terminating complex s expression reg map";
const s_register_operator_CFL_t avxtepldmh[10] = {{2,{.operator_value = 2}},{2,{.operator_value = 0}},{0,{.value = 3}},{0,{.value = 4}},{3,{.end = 0}},{2,{.operator_value = 0}},{0,{.value = 5}},{0,{.value = 6}},{3,{.end = 0}},{3,{.end = 0}},};
const  s_register_definition_CFL_t nolfidfpqa = {0,9,8,10,avxtepldmh};
static const s_reg_expression_CFL_t brgxsqgyct = {0,0,&nolfidfpqa};
static const dump_register_buffer_CFL_t xlufyixxej = {0,32};
const s_register_operator_CFL_t pkcgursqoj[22] = {{2,{.operator_value = 0}},{2,{.operator_value = 2}},{2,{.operator_value = 0}},{0,{.value = 3}},{0,{.value = 4}},{3,{.end = 0}},{2,{.operator_value = 0}},{0,{.value = 5}},{0,{.value = 6}},{3,{.end = 0}},{3,{.end = 0}},{2,{.operator_value = 2}},{2,{.operator_value = 0}},{0,{.value = 3}},{0,{.value = 4}},{3,{.end = 0}},{2,{.operator_value = 0}},{0,{.value = 5}},{0,{.value = 6}},{3,{.end = 0}},{3,{.end = 0}},{3,{.end = 0}},};
const  s_register_definition_CFL_t jlltiponfh = {0,9,12,22,pkcgursqoj};
static const s_reg_expression_CFL_t roouxpzzdi = {0,0,&jlltiponfh};
static const dump_register_buffer_CFL_t pabfizbkdc = {0,32};
const s_register_operator_CFL_t fjukiokxjw[46] = {{2,{.operator_value = 2}},{2,{.operator_value = 0}},{2,{.operator_value = 2}},{2,{.operator_value = 0}},{0,{.value = 3}},{0,{.value = 4}},{3,{.end = 0}},{2,{.operator_value = 0}},{0,{.value = 5}},{0,{.value = 6}},{3,{.end = 0}},{3,{.end = 0}},{2,{.operator_value = 2}},{2,{.operator_value = 0}},{0,{.value = 3}},{0,{.value = 4}},{3,{.end = 0}},{2,{.operator_value = 0}},{0,{.value = 5}},{0,{.value = 6}},{3,{.end = 0}},{3,{.end = 0}},{3,{.end = 0}},{2,{.operator_value = 0}},{2,{.operator_value = 2}},{2,{.operator_value = 0}},{0,{.value = 3}},{0,{.value = 4}},{3,{.end = 0}},{2,{.operator_value = 0}},{0,{.value = 5}},{0,{.value = 6}},{3,{.end = 0}},{3,{.end = 0}},{2,{.operator_value = 2}},{2,{.operator_value = 0}},{0,{.value = 3}},{0,{.value = 4}},{3,{.end = 0}},{2,{.operator_value = 0}},{0,{.value = 5}},{0,{.value = 6}},{3,{.end = 0}},{3,{.end = 0}},{3,{.end = 0}},{3,{.end = 0}},};
const  s_register_definition_CFL_t hwpmpcyvfq = {0,9,20,46,fjukiokxjw};
static const s_reg_expression_CFL_t apargrxohi = {0,0,&hwpmpcyvfq};
static const dump_register_buffer_CFL_t cgzifbprkw = {0,32};
static const char *pfqlalczmu = "wait test";
static const clear_register_map_CFL_t ynupfupjnz = {0,1,0,32};
const s_register_operator_CFL_t bgdylhaulx[4] = {{2,{.operator_value = 10}},{1,{.buffer_position = 0}},{1,{.buffer_position = 1}},{3,{.end = 0}},};
const  s_register_definition_CFL_t mbcdtwxdfq = {0,9,6,4,bgdylhaulx};
static const wait_reg_map_s_expr_CFL_t dsjhprribz = {&mbcdtwxdfq,NULL};

static While_control_RAM_CFL_t juttjsijdj_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t kvfjzqmlwj_rom = { 4000 ,true, &dsjhprribz,&juttjsijdj_ram,this_should_not_happen_fn};

    
static const char *anyraqosvx = "wait triggered";
static const unsigned short jjrccnsxog[] = { 6,7};
const Enable_column_CFL_t gqgxzgtlpn = { true, 2, jjrccnsxog };


unsigned  idhyvkjxaq;
const While_time_control_ROM_CFL_t rlcrllvpnt = { 10000,&idhyvkjxaq };



static While_control_RAM_CFL_t sgtoxdlvjg_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t btxcxvitxp_rom = { 0 ,true, &rlcrllvpnt,&sgtoxdlvjg_ram,null_function};

    
static const char *ygzfwbwbpr = "verify test started";
static const clear_register_map_CFL_t laklkqgfts = {0,0,0,32};
static const dump_register_buffer_CFL_t nbdgyyfykd = {0,32};
const s_register_operator_CFL_t kqymelqvvs[4] = {{2,{.operator_value = 9}},{1,{.buffer_position = 0}},{1,{.buffer_position = 1}},{3,{.end = 0}},};
const  s_register_definition_CFL_t jreehxiudp = {0,9,6,4,kqymelqvvs};
static const  verify_reg_map_s_expr_CFL_t munioasjtk = {&jreehxiudp,NULL};
    static Verify_control_ROM_CFL_t gakjvtizxz_rom = { true, (void *)&munioasjtk, reg_verify_trigger_fn };  // terminate flag,user data,one shot function


unsigned  ytxdovfual;
const While_time_control_ROM_CFL_t hgtbhgaraa = { 15000,&ytxdovfual };



static While_control_RAM_CFL_t kemuwkmure_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t ojkgwkwqey_rom = { 0 ,true, &hgtbhgaraa,&kemuwkmure_ram,null_function};

    
static const char *toryepsviz = "This step should not occur as column would be terminated by verify fail";


unsigned  dhyoxxpekz;
const While_time_control_ROM_CFL_t rnzaqgvwof = { 3000,&dhyoxxpekz };



static While_control_RAM_CFL_t ydzbpaxzar_ram = { 0 };  // current count 


  

static const While_control_ROM_CFL_t rpuenhqzbm_rom = { 0 ,true, &rnzaqgvwof,&ydzbpaxzar_ram,null_function};

    
static const char *nzbhaqceqo = "triggering verify fail";
static const int16_t cfauuqdlsz[1] = {1};
static const set_register_buffer_CFL_t falbivzhar = {0,0,1,cfauuqdlsz};
static const reg_my_then_one_shot_CFL_t mqsjkoanaj = {0,0,700};
static const reg_my_else_one_shot_CFL_t kzirpfoeeq = {"This is the message from else one shot\n"};
static const char *cuqaqtqjsn = "if then else test";
static const char *vuogazvbgf = "then test";
static const clear_register_map_CFL_t wbxdchbpob = {0,1,0,32};
static const if_then_else_reg_map_CFL_t ssjmzbmmfv = {0,0,reg_my_then_one_shot_fn, reg_my_else_one_shot_fn,&mqsjkoanaj,&kzirpfoeeq};
static const dump_register_buffer_CFL_t nepdgzldow = {0,32};
static const clear_register_map_CFL_t dlaoeneqxp = {0,0,0,32};
static const if_then_else_reg_map_CFL_t rzasrrshwv = {0,0,reg_my_then_one_shot_fn, reg_my_else_one_shot_fn,&mqsjkoanaj,&kzirpfoeeq};
static const dump_register_buffer_CFL_t voxhlmcqef = {0,32};


//----------RAM data structures for columns ----

unsigned yguzfthtgj[8];
Watch_dog_struct_CFL_t * rrhqdtfizz[8];
unsigned char xcadwegpez[8];
unsigned char ubksuudxuo[8];
void* zivzmfrzsh[8];
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

static const Column_ROM_CFL_t jzxmzrsfhw[] = {
  { -1,true, 0, 5, 0, -1, -1 },
  { -1,false, 1, 22, 5, -1, -1 },
  { -1,false, 2, 56, 27, -1, -1 },
  { -1,false, 3, 8, 83, -1, -1 },
  { -1,false, 4, 9, 109, -1, -1 },
  { -1,false, 5, 7, 91, -1, -1 },
  { -1,false, 6, 7, 98, -1, -1 },
  { -1,false, 7, 4, 105, -1, -1 },
};


//----------Column elements RAM structures----



static unsigned char udaccpbxwk[118];


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

static const Column_element_CFL_t qmqhzgzhpl[] = {
    {one_shot_handler_CFL,log_message_CFL,(void *)&weinumltrh},
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&etwmdqjecv},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&pmokfduqjd_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&kiicbnrssc},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&xsmywqifno},
    {one_shot_handler_CFL,dump_register_buffer_CFL,(void *)&tkrygcupui},
    {one_shot_handler_CFL,dump_register_buffer_CFL,(void *)&joixkkssxv},
    {one_shot_handler_CFL,clear_register_map_CFL,(void *)&ktfwieejbv},
    {one_shot_handler_CFL,clear_register_map_CFL,(void *)&evvzpprwzk},
    {one_shot_handler_CFL,dump_register_buffer_CFL,(void *)&glaspwvwik},
    {one_shot_handler_CFL,dump_register_buffer_CFL,(void *)&shcfszzzhg},
    {one_shot_handler_CFL,clear_register_map_CFL,(void *)&macijfcwrj},
    {one_shot_handler_CFL,clear_register_map_CFL,(void *)&tjccsfptoz},
    {one_shot_handler_CFL,dump_register_buffer_CFL,(void *)&aisjaoyrst},
    {one_shot_handler_CFL,dump_register_buffer_CFL,(void *)&jfvwcukzrr},
    {one_shot_handler_CFL,clear_register_map_CFL,(void *)&flijoosjke},
    {one_shot_handler_CFL,clear_register_map_CFL,(void *)&jebcseripn},
    {one_shot_handler_CFL,dump_register_buffer_CFL,(void *)&whmuartfcj},
    {one_shot_handler_CFL,dump_register_buffer_CFL,(void *)&uuxwugpwuy},
    {one_shot_handler_CFL,set_register_buffer_CFL,(void *)&lrtpyosodj},
    {one_shot_handler_CFL,set_register_buffer_CFL,(void *)&irmzxysvec},
    {one_shot_handler_CFL,dump_register_buffer_CFL,(void *)&frgnerypyr},
    {one_shot_handler_CFL,dump_register_buffer_CFL,(void *)&arlibjhmif},
    {one_shot_handler_CFL,register_map_copy_CFL,(void *)&hvrhtlntnj},
    {one_shot_handler_CFL,dump_register_buffer_CFL,(void *)&jarauhgxzd},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&xjungcdmzg},
    {one_shot_handler_CFL,clear_register_map_CFL,(void *)&eafmliujbw},
    {one_shot_handler_CFL,set_register_buffer_CFL,(void *)&ocgwacynkw},
    {one_shot_handler_CFL,dump_register_buffer_CFL,(void *)&jtxhfipyxj},
    {one_shot_handler_CFL,reg_map_s_expr_CFL,(void *)&jvghynhpeg},
    {one_shot_handler_CFL,dump_register_buffer_CFL,(void *)&fvsrgisrax},
    {one_shot_handler_CFL,reg_map_s_expr_CFL,(void *)&pgvkqmgpbx},
    {one_shot_handler_CFL,dump_register_buffer_CFL,(void *)&wezmslxvgh},
    {one_shot_handler_CFL,reg_map_s_expr_CFL,(void *)&utkxyhxlas},
    {one_shot_handler_CFL,dump_register_buffer_CFL,(void *)&jtvqwmriet},
    {one_shot_handler_CFL,set_register_buffer_CFL,(void *)&wygnckbjlg},
    {one_shot_handler_CFL,dump_register_buffer_CFL,(void *)&wugceogqdn},
    {one_shot_handler_CFL,reg_map_s_expr_CFL,(void *)&ujuoguctot},
    {one_shot_handler_CFL,dump_register_buffer_CFL,(void *)&vvmmwwicol},
    {one_shot_handler_CFL,reg_map_s_expr_CFL,(void *)&egsuqafrey},
    {one_shot_handler_CFL,dump_register_buffer_CFL,(void *)&rthynndwva},
    {one_shot_handler_CFL,reg_map_s_expr_CFL,(void *)&zhjwtkdhyl},
    {one_shot_handler_CFL,dump_register_buffer_CFL,(void *)&lgtupntkzd},
    {one_shot_handler_CFL,reg_map_s_expr_CFL,(void *)&pdzpqfhbea},
    {one_shot_handler_CFL,dump_register_buffer_CFL,(void *)&fedvydthst},
    {one_shot_handler_CFL,reg_map_s_expr_CFL,(void *)&ooqorgugbl},
    {one_shot_handler_CFL,dump_register_buffer_CFL,(void *)&bgcpttchiv},
    {one_shot_handler_CFL,reg_map_s_expr_CFL,(void *)&nvodgerqjn},
    {one_shot_handler_CFL,dump_register_buffer_CFL,(void *)&bslcnnuloq},
    {one_shot_handler_CFL,reg_map_s_expr_CFL,(void *)&gzcbpgqers},
    {one_shot_handler_CFL,dump_register_buffer_CFL,(void *)&bjliiqraok},
    {one_shot_handler_CFL,reg_map_s_expr_CFL,(void *)&hpochygash},
    {one_shot_handler_CFL,dump_register_buffer_CFL,(void *)&pibhjtwuxf},
    {one_shot_handler_CFL,reg_map_s_expr_CFL,(void *)&fpsdpislro},
    {one_shot_handler_CFL,dump_register_buffer_CFL,(void *)&atddypqrfo},
    {one_shot_handler_CFL,reg_map_s_expr_CFL,(void *)&taplowmgby},
    {one_shot_handler_CFL,dump_register_buffer_CFL,(void *)&xctfclljib},
    {one_shot_handler_CFL,reg_map_s_expr_CFL,(void *)&wgbqdquask},
    {one_shot_handler_CFL,dump_register_buffer_CFL,(void *)&wdunxjgnta},
    {one_shot_handler_CFL,reg_map_s_expr_CFL,(void *)&vucrghujgn},
    {one_shot_handler_CFL,dump_register_buffer_CFL,(void *)&qtrxmarflo},
    {one_shot_handler_CFL,reg_map_s_expr_CFL,(void *)&tqjvgnurfr},
    {one_shot_handler_CFL,dump_register_buffer_CFL,(void *)&rfmvqjlrvt},
    {one_shot_handler_CFL,reg_map_s_expr_CFL,(void *)&jfkydpuzrx},
    {one_shot_handler_CFL,dump_register_buffer_CFL,(void *)&vavqfwdqdy},
    {one_shot_handler_CFL,reg_map_s_expr_CFL,(void *)&fjenmuxfes},
    {one_shot_handler_CFL,dump_register_buffer_CFL,(void *)&hnznsdciis},
    {one_shot_handler_CFL,reg_map_s_expr_CFL,(void *)&xksdpejhfl},
    {one_shot_handler_CFL,dump_register_buffer_CFL,(void *)&zgwybznhqc},
    {one_shot_handler_CFL,reg_map_s_expr_CFL,(void *)&wrwkbfpobs},
    {one_shot_handler_CFL,dump_register_buffer_CFL,(void *)&hvwhqyjbxy},
    {one_shot_handler_CFL,reg_map_s_expr_CFL,(void *)&dxpcydncgv},
    {one_shot_handler_CFL,dump_register_buffer_CFL,(void *)&qzeeznnslp},
    {one_shot_handler_CFL,reg_map_s_expr_CFL,(void *)&tvldqnhnub},
    {one_shot_handler_CFL,dump_register_buffer_CFL,(void *)&aqppwgsbvp},
    {one_shot_handler_CFL,reg_map_s_expr_CFL,(void *)&oouyzlyzas},
    {one_shot_handler_CFL,dump_register_buffer_CFL,(void *)&kgkjdhpwwj},
    {one_shot_handler_CFL,reg_map_s_expr_CFL,(void *)&njvhyudydb},
    {one_shot_handler_CFL,dump_register_buffer_CFL,(void *)&butuchtdnb},
    {one_shot_handler_CFL,log_message_CFL,(void *)&aesjowtruj},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&dpqxvzxahq},
    {one_shot_handler_CFL,reg_map_s_expr_CFL,(void *)&brgxsqgyct},
    {one_shot_handler_CFL,dump_register_buffer_CFL,(void *)&xlufyixxej},
    {one_shot_handler_CFL,reg_map_s_expr_CFL,(void *)&roouxpzzdi},
    {one_shot_handler_CFL,dump_register_buffer_CFL,(void *)&pabfizbkdc},
    {one_shot_handler_CFL,reg_map_s_expr_CFL,(void *)&apargrxohi},
    {one_shot_handler_CFL,dump_register_buffer_CFL,(void *)&cgzifbprkw},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&pfqlalczmu},
    {one_shot_handler_CFL,clear_register_map_CFL,(void *)&ynupfupjnz},
    {while_handler_CFL,wait_reg_map_s_expr_CFL,(void *)&kvfjzqmlwj_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&anyraqosvx},
    {bidirectional_one_shot_handler_CFL,enable_columns_function_CFL,(void *)&gqgxzgtlpn},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&btxcxvitxp_rom},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&ygzfwbwbpr},
    {one_shot_handler_CFL,clear_register_map_CFL,(void *)&laklkqgfts},
    {one_shot_handler_CFL,dump_register_buffer_CFL,(void *)&nbdgyyfykd},
    {verify_handler_CFL,verify_reg_map_s_expr_CFL,(void *)&gakjvtizxz_rom},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&ojkgwkwqey_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&toryepsviz},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {while_handler_CFL,wait_time_delay_CFL,(void *)&rpuenhqzbm_rom},
    {one_shot_handler_CFL,log_message_CFL,(void *)&nzbhaqceqo},
    {one_shot_handler_CFL,set_register_buffer_CFL,(void *)&falbivzhar},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
    {one_shot_handler_CFL,log_message_CFL,(void *)&cuqaqtqjsn},
    {one_shot_handler_CFL,log_message_CFL,(void *)&vuogazvbgf},
    {one_shot_handler_CFL,clear_register_map_CFL,(void *)&wbxdchbpob},
    {one_shot_handler_CFL,if_then_else_CFL,(void *)&ssjmzbmmfv},
    {one_shot_handler_CFL,dump_register_buffer_CFL,(void *)&nepdgzldow},
    {one_shot_handler_CFL,clear_register_map_CFL,(void *)&dlaoeneqxp},
    {one_shot_handler_CFL,if_then_else_CFL,(void *)&rzasrrshwv},
    {one_shot_handler_CFL,dump_register_buffer_CFL,(void *)&voxhlmcqef},
    {return_condition_code_CFL,NULL,(void *)terminate_buffer},
};
Bitmap_CFL khrhwqfzzj[0];
static int16_t duoitgxzvg[32]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
static int16_t mdtbltrxpb[32]= {32767,32767,32767,32767,32767,32767,32767,32767,32767,32767,32767,32767,32767,32767,32767,32767,32767,32767,32767,32767,32767,32767,32767,32767,32767,32767,32767,32767,32767,32767,32767,32767};
Registermap_CFL_t qbuertmmab[2] = {
 {32, &duoitgxzvg[0]},
 {32, &mdtbltrxpb[0]},
};
const Sm_control_ROM_CFL_t ezrvfulimm[0];
Sm_control_RAM_CFL_t mpyzvptywz[0];


static Time_control_CFL_t dfqeboabzm;




static Engine_control_CFL_t pjplotcfmi;


/* remaining allocate heap size */

static unsigned czdanxeops;


/* current heap pointer */

static char* uulwprbzdy;


/* heap block area */

static CS_MEMORY_CONTROL lwzqgpeaza;


    
    


const struct Handle_CFL_t twkbsdnngo =
{

  .queue_number = 1,
  .queue_rom = yhjbvilkwe,
  .queue_ram = fjflhhxadz,

  .column_elements_flags =udaccpbxwk,
  .column_elements_ROM = qmqhzgzhpl,

  .watch_dog_struct = rrhqdtfizz,
  .watch_dog_count  = yguzfthtgj,
   
   
  .column_flags = xcadwegpez,
  .column_local_data = zivzmfrzsh,
  .column_state = ubksuudxuo,
  .number_of_columns = 8,
  .column_rom_data = jzxmzrsfhw,

  
  
  
  .time_control = &dfqeboabzm,
  .engine_control =&pjplotcfmi,
  .debug_function = debug_write,
  .malloc = private_heap_malloc_CFL,
  .free = private_heap_free_CFL,
  .allocate_once = allocate_once_CFL,
  .master_heap_starting_location = &allocate_once_memory,
  .master_heap_size = 10000,
  .remaining_heap_size = &czdanxeops,
  .current_heap_location = &uulwprbzdy,
  .private_heap   = &lwzqgpeaza,
  .private_heap_size =   1000,
  .number_of_sm      = 0,
  .sm_rom     =  ezrvfulimm,
  .sm_ram     = mpyzvptywz,
  .number_of_bitmaps = 0,
  .bitmaps = khrhwqfzzj,
  .number_of_registermaps = 2,
  .registermaps = qbuertmmab
} ;

const Handle_CFL_t*  register_map_1_handle(){
    return &twkbsdnngo;
}
   

#ifdef __cplusplus
}
#endif

#endif
