#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void clear_screen()
{
    printf("\033[H\033[J");
}

void proc()
{
    FILE *proc_file;
    char proc_buffer[256];
    const char *cpu0 = "cpu0";  
    const char *cpu1 = "cpu1";
    const char *cpu2 = "cpu2";
    const char *cpu3 = "cpu3";
    const char *processes = "processes";
    const char *procs_running = "procs_running";
    const char *procs_blocked = "procs_blocked";

    proc_file = fopen("/proc/stat", "r");
    if (proc_file == NULL)
    {
        printf("Error: file not opened.\n");
    }

    while(fgets(proc_buffer, sizeof(proc_buffer), proc_file))
    {
        if (strncmp(proc_buffer, cpu0, strlen(cpu0)) == 0)
        {
            printf("Core 0: %s \n", proc_buffer);
        }
        if (strncmp(proc_buffer, cpu1, strlen(cpu1)) == 0)
        {
            printf("Core 1: %s \n", proc_buffer);
        }
        if (strncmp(proc_buffer, cpu2, strlen(cpu2)) == 0)
        {
            printf("Core 2: %s \n", proc_buffer);
        }
        if (strncmp(proc_buffer, cpu3, strlen(cpu3)) == 0)
        {
            printf("Core 3: %s \n", proc_buffer);
        }
        if (strncmp(proc_buffer, processes, strlen(processes)) == 0)
        {
            printf("Active processes: %s \n", proc_buffer);
        }
        if (strncmp(proc_buffer, procs_running, strlen(procs_running)) == 0)
        {
            printf("Running procs: %s \n", proc_buffer);
        }
        if (strncmp(proc_buffer, procs_blocked, strlen(procs_blocked)) == 0)
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

    const char *mem_total = "MemTotal";
    const char *mem_free = "MemFree";
    const char *mem_available = "MemAvailable";

    mem_file = fopen("/proc/meminfo", "r");
    if (mem_file == NULL)
    {
        printf("Error: file not opened.\n");
    }
    
    while(fgets(mem_buffer, sizeof(mem_buffer), mem_file))
    {
        if (strncmp(mem_buffer, mem_total, strlen(mem_total)) == 0)
        {
            printf("%s \n", mem_buffer);
        }
        if (strncmp(mem_buffer, mem_free, strlen(mem_free)) == 0)
        {
            printf("%s \n", mem_buffer);
        }
        if (strncmp(mem_buffer, mem_available, strlen(mem_available)) == 0)
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
