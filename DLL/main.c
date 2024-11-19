#include <stdio.h>
#include <dlfcn.h>

int main() {
    // 加载共享库
    void *handle = dlopen("./libsum.so", RTLD_LAZY);
    if (!handle) {
        printf("无法加载共享库: %s\n", dlerror());
        return -1;
    }

    // 获取 'sum' 函数的地址
    int (*sum)(int, int) = dlsym(handle, "sum");
    if (!sum) {
        printf("无法找到函数 'sum': %s\n", dlerror());
        dlclose(handle);  // 关闭共享库
        return -1;
    }

    // 调用 'sum' 函数
    int result = sum(5, 3);
    printf("5 + 3 = %d\n", result);

    // 关闭共享库
    dlclose(handle);

    return 0;
}