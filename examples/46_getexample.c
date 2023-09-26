#include <curl/curl.h>
#include <stdio.h>
#include <unistd.h>

size_t writefunc(void *ptr, size_t size, size_t nmemb, void *unused)
{
	write(STDOUT_FILENO, ptr, size * nmemb);
	return size * nmemb;
}

#define URL "http://example.com"

int main()
{
	printf("Loading " URL "\n");
	CURL *curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_URL, URL);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
	curl_easy_perform(curl);
	curl_easy_cleanup(curl);
	return 0;
}