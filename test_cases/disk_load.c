#include <stdio.h> 
#include <sys/time.h>   
#include <sys/resource.h> 

///////////////////////////////////
// measure user and system time using the "getrusage" call. 
///////////////////////////////////
//struct rusage {
//   struct timeval ru_utime; /* user CPU time used */
//   struct timeval ru_stime; /* system CPU time used */
//   long   ru_maxrss;        /* maximum resident set size */
//   long   ru_ixrss;         /* integral shared memory size */
//   long   ru_idrss;         /* integral unshared data size */
//   long   ru_isrss;         /* integral unshared stack size */
//   long   ru_minflt;        /* page reclaims (soft page faults) */
//   long   ru_majflt;        /* page faults (hard page faults) */
//   long   ru_nswap;         /* swaps */
//   long   ru_inblock;       /* block input operations */
//   long   ru_oublock;       /* block output operations */
//   long   ru_msgsnd;        /* IPC messages sent */
//   long   ru_msgrcv;        /* IPC messages received */
//   long   ru_nsignals;      /* signals received */
//   long   ru_nvcsw;         /* voluntary context switches */
//   long   ru_nivcsw;        /* involuntary context switches */
//};

//struct timeval
//  {
//    long int tv_sec;       /* Seconds.  */
//    long int tv_usec;      /* Microseconds.  */
//  };


int main () { 

	/*
		getrusage
	*/
    struct rusage buf; 
    struct timeval start, end;

    FILE *fPtr = fopen("dump.txt", "a");

    gettimeofday(&start, NULL);
    // chew up some CPU time
    int i;
    for (i=0; i<20000000; i++) {
        fprintf(fPtr, "%d", i);
    }
    fclose(fPtr);
    remove("dump.txt");
    getrusage(RUSAGE_SELF, &buf); 
    gettimeofday(&end, NULL);
    printf("Total user time in milliseconds: %f\n", 
	   (double) buf.ru_utime.tv_sec*1000 
	 + (double) buf.ru_utime.tv_usec / (double) 1000); 

    printf("Total system time in milliseconds: %f\n", 
	   (double) buf.ru_stime.tv_sec*1000 
	 + (double) buf.ru_stime.tv_usec / (double) 1000);

	printf("Wallclock time in milliseconds: %f\n", ((end.tv_sec * 1000 + end.tv_usec/ (double) 1000)
	 - (start.tv_sec * 1000 + start.tv_usec/ (double) 1000))); 
}
