#include<stdio.h>


int main()
{
	char fname[100] = "time.log";
	FILE* fp;
	int min, sec,numtime=0,sumtime=0 ,avtime=0, maxtime=0;

	fp = fopen(fname, "r");
	
	if (fp == NULL) {
		printf("Failed to open file\n");
		return 0;
	}

	while(!feof(fp)) {
		fscanf(fp, "(%d:%d)\n", &min, &sec);
		printf("min = %d, sec = %d\n", min, sec);
		numtime+=1;
		sumtime=min*60+sec+sumtime;
		avtime=sumtime/numtime;
		if (maxtime < min*60+sec)
			maxtime=min*60+sec;
		// get min, max, avg access time 

	}
	printf("평 균시간 %d분 %d초", avtime/60, avtime%60);
	printf("최대 시간 %d분 %d초", maxtime/60, maxtime%60);

	return 0;
}

