#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void clear_screen()
{
    printf("\033[H\033[J");
}

void core_stat(const char *buffer, const char *core_name, const char *core_lable)
{
	char *token = strstr(buffer, core_lable);
	if (token != NULL)
	{
		token += strlen(core_lable);

		while (*token == ' ')
		{
			token++;
		}
		
		printf("%s: %s\n", core_name, token);	
	}
}

void proc()
{
    FILE *proc_file;
    char proc_buffer[256];
    const char *CPU0 = "cpu0";  
    const char *CPU1 = "cpu1";
    const char *CPU2 = "cpu2";
    const char *CPU3 = "cpu3";
    const char *PROCESSES = "processes";
    const char *PROCS_RUNNING = "procs_running";
    const char *PROCS_BLOCKED = "procs_blocked";

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

void memory()
{
    FILE *mem_file;
    char mem_buffer[256];

    const char *MEM_TOTAL = "MemTotal";
    const char *MEM_FREE = "MemFree";
    const char *MEM_AVAILABLE = "MemAvailable";

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
