#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// 主要功能：使用libcurl库下载网页内容到文件

FILE *fp;
int write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
    int written = fwrite(ptr, size, nmemb, (FILE *)fp);
    return written;
}

int main()
{
    const char *path = "/tmp/curl-test";
    const char *mode = "w";
    fp = fopen(path, mode);

    // 初始化libcurl库
    curl_global_init(CURL_GLOBAL_ALL);

    // 初始化一个CURL类型的指针
    CURL *curl = curl_easy_init();
    // 设置libcurl选项
    curl_easy_setopt(curl, CURLOPT_URL, "https://baike.baidu.com/item/cmake/7138032");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);

    // 执行操作
    CURLcode res = curl_easy_perform(curl);

    curl_easy_cleanup(curl);
}
