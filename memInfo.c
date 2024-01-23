#include <stdlib.h>

int main()
{
    system("echo \"Kernel Info: \"");
    system("cat /proc/version_signature | awk '{printf \"Kernel Version: %s\\n\", $0}'");
    system("echo \"\n### Memory status: \"");
    system("cat /proc/meminfo | awk '/Mem/ {print}'");
    return 0;
}