#ifndef util_h
#define util_h
#define MAX_RANGE 999
/*
*defined functions in header file they have been provided by the pdf file
*
*only one of the functions has been defined by me create_loop_len func is required to calculate the loop len and fill the pointer
*
*
*
*/
void generate_sequance(int xs,int currentlen, int seqlen, int *seq);
void check_loop_iterative(void (*f)(int, int ,int ,int*),int xs,int seqlen,int *loop,int *looplen);
int has_loop(int *arr,int n,int looplen,int *ls,int *le);
void create_loop_len(int *looplen,int seqlen);
void hist_of_firstdigits(void (*f)(int,int,int,int *),int xs,int seqlen,int *h,int digit);

#endif
