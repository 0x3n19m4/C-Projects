#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define CPU0 "cpu0"  
#define CPU1 "cpu1"
#define CPU2 "cpu2"
#define CPU3 "cpu3"
#define CPU4 "cpu4"  
#define CPU5 "cpu5"
#define CPU6 "cpu6"
#define CPU7 "cpu7"
#define PROCESSES "processes"
#define PROCS_RUNNING "procs_running"
#define PROCS_BLOCKED "procs_blocked"

void clear_screen()
{
    printf("\033[H\033[J");
}

void core_stat(const char *BUFFER, const char *CORE_NAME, const char *CORE_LABLE)
{
	char *token = strstr(BUFFER, CORE_LABLE);
	if (token != NULL)
	{
		token += strlen(CORE_LABLE);

		while (*token == ' ')
		{
			token++;
		}
		
		printf("%s: %s\n", CORE_NAME, token);	
	}
}

void proc()
{
    FILE *proc_file;
    char proc_buffer[512];

    proc_file = fopen("/proc/stat", "r");
    if (proc_file == NULL)
    {
        printf("Error: file not opened.\n");
    }

    while(fgets(proc_buffer, sizeof(proc_buffer), proc_file))
    {
        if (strncmp(proc_buffer, CPU0, strlen(CPU0)) == 0)
        {
            core_stat(proc_buffer, "Core 0", "cpu0");
        }
        if (strncmp(proc_buffer, CPU1, strlen(CPU1)) == 0)
        {
            core_stat(proc_buffer, "Core 1", "cpu1");
        }
        if (strncmp(proc_buffer, CPU2, strlen(CPU2)) == 0)
        {
            core_stat(proc_buffer, "Core 2", "cpu2");
        }
        if (strncmp(proc_buffer, CPU3, strlen(CPU3)) == 0)
        {
            core_stat(proc_buffer, "Core 3", "cpu3");
        }
        if (strncmp(proc_buffer, CPU4, strlen(CPU4)) == 0)
        {
            core_stat(proc_buffer, "Core 4", "cpu4");
        }
        if (strncmp(proc_buffer, CPU5, strlen(CPU5)) == 0)
        {
            core_stat(proc_buffer, "Core 5", "cpu5");
        }
        if (strncmp(proc_buffer, CPU6, strlen(CPU6)) == 0)
        {
            core_stat(proc_buffer, "Core 6", "cpu6");
        }
        if (strncmp(proc_buffer, CPU7, strlen(CPU7)) == 0)
        {
            core_stat(proc_buffer, "Core 7", "cpu7");
        }
        if (strncmp(proc_buffer, PROCESSES, strlen(PROCESSES)) == 0)
        {
            printf("Active processes: %s \n", proc_buffer);
        }
        if (strncmp(proc_buffer, PROCS_RUNNING, strlen(PROCS_RUNNING)) == 0)
        {
            printf("Running procs: %s \n", proc_buffer);
        }
        if (strncmp(proc_buffer, PROCS_BLOCKED, strlen(PROCS_BLOCKED)) == 0)
        {
            printf("Blocked procs: %s \n", proc_buffer);
        }
    }

    fclose(proc_file);
}

#define MEM_TOTAL "MemTotal"
#define MEM_FREE "MemFree"
#define MEM_AVAILABLE "MemAvailable"

void memory()
{
    FILE *mem_file;
    char mem_buffer[256];

    mem_file = fopen("/proc/meminfo", "r");
    if (mem_file == NULL)
    {
        printf("Error: file not opened.\n");
    }
    
    while(fgets(mem_buffer, sizeof(mem_buffer), mem_file))
    {
        if (strncmp(mem_buffer, MEM_TOTAL, strlen(MEM_TOTAL)) == 0)
        {
            printf("%s \n", mem_buffer);
        }
        if (strncmp(mem_buffer, MEM_FREE, strlen(MEM_FREE)) == 0)
        {
            printf("%s \n", mem_buffer);
        }
        if (strncmp(mem_buffer, MEM_AVAILABLE, strlen(MEM_AVAILABLE)) == 0)
        {
            printf("%s \n", mem_buffer);
        }
    }

    fclose(mem_file);
}

int main()
{
    while (1)
    {
        clear_screen();
        proc();
        memory();
        sleep(2);
    }
    return 0; 
}
