#define _GNU_SOURCE
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>

#include "util.h"
#include "process.h"


Process *parse_file(FILE * f)
{
	size_t s = 0;
	char *headers = NULL;
	size_t line_len = 0;
	line_len = getline(&headers, &line_len, f);
	free(headers);

	
	Process *pptr = (Process *) malloc(P_SIZE * sizeof(Process));
	while (!feof(f)) {
		int t_pid, t_arrival_time, t_priority;
		fscanf(f, "%d,%d,%d\n", &t_pid, &t_arrival_time, &t_priority);
		process_ctr(&pptr[s], t_pid, t_arrival_time, t_priority);
		s++;
	}

	return pptr;
}