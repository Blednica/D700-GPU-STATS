//D700 GPU Mac Pro 2013
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    FILE *fp;
    char line[1024];

    while (1) {
        system("clear");
        printf("===D700 GPU/system monitor===");

        fp = popen("system_profiler, SPDisplaysDataType", "r");
        if (fp != NULL) {
            while (fgets(line, sizeof(line), fp) != NULL) {
                if (strstr(line, "Chipset Model") ||
                    strstr(line, "VRAM") ||
                    strstr(line, "Metal")) {

                    printf("%s", line);
                }
            }

            pclose(fp);
        }
        //CPU Usage
        printf("n\=== CPU USAGE ===\n\n");
        fp = popen("top -L 1 | grep 'CPU usage'", "r");
        if (fp != NULL) {
            while (fgets(line, sizeof(line), fp) != NULL) {
                printf("%s", line);
            }
            pclose(fp);
        }
        //Memory Usage
        printf("n\=== Memory USAGE ===\n\n");
        fp = popen ("vm_stat", "r");
        if (fp != NULL) {
            int count = 0;
            while (fgets(line, sizeof(line), fp) != NULL && count < 5) {
                printf("%s", line);
                count++;
            }
            pclose(fp);
        }
        //GPU Activity
        printf("\n=== GPU Activity ===\n\n");
        fp = popen("powermetrics --samplers gpu_power -n 1 2>/dev/null", "r");
        if (fp != NULL) {
            while (fgets(line, sizeof(line), fp) != NULL) {
                if (strstr(line, "GPU") ||
                    strstr(line, "gpu"))  {
                        printf("%s", line);
            }
        }
        pclose(fp);

    }
    printf("\nRefreshing in 6 seconds...\n");
    sleep(6);
}
return 0;
}
