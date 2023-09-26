#include <curl/curl.h>
#include <stdio.h>
#include <unistd.h>

size_t writefunc(void *ptr, size_t size, size_t nmemb, void *unused)
{
	write(STDOUT_FILENO, ptr, size * nmemb);
	return size * nmemb;
}

#define URL "http://example.com"
#define DATA "data=hellofromcurl"

int main()
{
	printf("Posting " DATA " to " URL "\n");
	CURL *curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_URL, URL);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
	// That's all you need to do POST queries, the output will be ignored by example.com though
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, DATA);
	curl_easy_perform(curl);
	curl_easy_cleanup(curl);
	return 0;
}