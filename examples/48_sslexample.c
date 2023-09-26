#include <curl/curl.h>
#include <stdio.h>
#include <unistd.h>

#define URL "https://example.com"

size_t nop(void *ptr, size_t size, size_t nmemb, void *unused)
{
	return size * nmemb;
}

int main()
{
	printf("Loading " URL "\n");
	CURL *curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_URL, URL);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, nop);
	curl_easy_setopt(curl, CURLOPT_CERTINFO, 1);
	curl_easy_perform(curl);
	struct curl_certinfo *certinfo;
	curl_easy_getinfo(curl, CURLINFO_CERTINFO, &certinfo);
	if (certinfo)
	{
		for (int i = 0; i < certinfo->num_of_certs; i++)
		{
			struct curl_slist *slist;
			for (slist = certinfo->certinfo[i]; slist; slist = slist->next)
				printf("%s\n", slist->data);
		}
	}
	else
		printf("Error loading SSL information\n");

	curl_easy_cleanup(curl);
	return 0;
}