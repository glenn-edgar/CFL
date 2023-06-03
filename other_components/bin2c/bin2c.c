/*
* bin2c.c
* convert files to byte arrays for automatic loading with lua_dobuffer
* Luiz Henrique de Figueiredo (lhf@tecgraf.puc-rio.br)
* 02 Apr 2003 20:44:31
*
* modified by glenn edgar glenn-edgar@onyxengr.com
* 10/27/2008
*
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define UNCOMPRESSED_SIZE 1000000

static int compressedSize = 0;

static int unCompressedSize = 0;
static unsigned char unCompressed[UNCOMPRESSED_SIZE];
static unsigned char compressed[UNCOMPRESSED_SIZE];


static void ltrim(char *string); // left trim name
static int maina(int argc, char* argv[]);
static void emit(const char* fn, int n);
static void fdump(const char* fn, int i);
static void dump(int n);
static void compressBuffer( void );
static void gatherBuffer( FILE  *f);

static char buffer[ 250000][256];
static char *argvv[250000];


int main( int argc, char *argv[] )
{
  FILE *input;
  char *result;
  int  i;

  if( argc < 2 )
  {
  
     exit(0);
  }
  
  input = fopen( argv[1] ,"r");
    if( input == NULL )
  {
 
     exit(0);
  }
  memset(buffer,0,sizeof(buffer));
  for( i = 1 ; i < 250000; i++ )
  {
    
    argvv[i] = &buffer[i][0];
    result = fgets( &buffer[i][0], 100, input );
    ltrim(&buffer[i][0]); // left trim name
    if( result == NULL )
    {
       break;
    }
  }
  fclose(input);
  maina( i, argvv );
}


static int maina(int argc, char* argv[])
{
 

 printf("/* code automatically generated by bin2c -- DO NOT EDIT */\n");
 printf("{\n");
 if (argc<2)
 {
   exit(0);
 }
 else
 {
  int i;
  printf("/* #include'ing this file in a C program is equivalent to calling\n");
  for (i=1; i<argc; i++) printf("  lua_dofile(L,\"%s\");\n",argv[i]);
  printf("*/\n");
  
  for (i=1; i<argc; i++) emit(argv[i],i);
 }
 printf("}\n");
 return 0;
}

static void emit(const char* fn, int n)
{ 
 unCompressedSize = 0;
 fdump(fn, n);
 compressBuffer();
 dump(n);
 //printf(" ficlLzUncompress((const unsigned char*)B%d, &unCompressed, &unCompressedSize );\n",n,n);
 //printf(" lua_dobuffer(L,(const char*)unCompressed,unCompressedSize,\"%s\");\n",fn);
 //printf(" if( unCompressed != NULL ) { free( unCompressed ); } ");
 printf(" lua_dobuffer(L,(const char*)B%d,sizeof(B%d),\"%s\");\n",n,n,fn);
}

static void dump(int n)
{
 int index;
 int tempIndex;
 int c;
 unsigned char *temp;

 tempIndex = 0;
 temp =compressed;
 printf("static const unsigned char B%d[]={\n",n);
 for (index=0; index < compressedSize;index++)
 {
  c = (int) *temp++;
   
  printf("%3u,",c);
  tempIndex++;
  if ( tempIndex==20) { putchar('\n'); tempIndex=0; }
 }
 printf("\n};\n\n");
}

static void fdump(const char* fn, int n)
{
  FILE* f= fopen(fn,"rb");		/* must open in binary mode */
 if (f==NULL)
 {
  fprintf(stderr,"bin2c: cannot open ");
  perror(fn);
  exit(1);
 }
 else
 {
  printf("/* %s */\n",fn);
  gatherBuffer(f);
  fclose(f);
 }
}



static void gatherBuffer( FILE  *f)
{
 char c;
 int   n;

 for (n=1;;n++)
 {
    c=getc(f); 
    unCompressed[ unCompressedSize ] = c;
    if (c==EOF) break;
    unCompressedSize +=1;

 }


}

static void compressBuffer( void )
{

 // ficlLzCompress(  unCompressed, 
 //                  unCompressedSize,
 //                  &compressed,
 //                  &compressedSize );
  assert( compressed != NULL );

  compressedSize = unCompressedSize;
  memcpy( compressed, unCompressed, compressedSize );
}



static void ltrim(char *string) // left trim name
{
   char *temp;

   temp = string + strlen(string);

   while( (*temp < '!' ) && ( temp != string ))
   {
      *temp-- = 0; // trim string
   }

}

