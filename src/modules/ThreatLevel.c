#include <stdio.h>
#include <curl/curl.h>

char* getThreatLevel()
{
	FILE* file = fopen("/tmp/currentThreatLevel.html", "w+");
	CURL* curl;
	CURLcode res;

	curl = curl_easy_init();
	if(curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, "https://isc.sans.edu/infocon.txt");
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);
		res = curl_easy_perform(curl);

		if (res != CURLE_OK)
		{
			fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
			fclose(file);
			curl_easy_cleanup(curl);
			return "Unavailable";
		}
		else
		{
			char* buffer;
			long size;
			size_t result;

			// Get file size
			fseek(file, 0, SEEK_END);
			size = ftell(file);
			rewind(file);
			if (size == NULL)
			{
				fprintf(stderr, "Threat level file is empty\n");
				fclose(file);
				return "Unavailable";
			}

			// Allocate memory
			buffer = (char*)malloc(sizeof(char)*size);
			if (buffer == NULL)
			{
				fprintf(stderr, "Unable to allocate memory.\n");
				fclose(file);
				return "Unavailable";
			}

			// Read file
			result = fread(buffer, 1, size, file);
			if (result != size)
			{
				fprintf(stderr, "Unable to read file\n");
			}

			fclose(file);
			curl_easy_cleanup(curl);
			return buffer;
		}
	}
	else
	{
		fclose(file);
		fprintf(stderr, "Unable to initialise CURL.\n");
		return "Unavailable";
	}
}