#include <iostream>
#include <string>

/* This function finds the number of characters that the URL's scheme and authority have. */
int findLength(std::string userURL, int startPos, std::string endMarker) {
	std::string tempURL = userURL.substr(startPos, userURL.length() - 1);
	int length = tempURL.find_first_of(endMarker);
	return length;
}

int main() {
	// Ask the user to input a URL and save it.
	std::cout << "Please enter a URL: ";
	std::string userURL;
	std::cin >> userURL;

	/* Find the lengths of each section with findLength(). For authorityLength, we add 
	2 to ignore the first 2 slashes that begin the authority. So, the function can find
	the slash the ends the authority. */
	int schemeLength = findLength(userURL, 0, "//");
	int authorityLength = findLength(userURL, schemeLength + 2, "/") + 2;
	int pathLength = userURL.length() - authorityLength - schemeLength;

	// Print out the scheme, authority, and path as substrings of the URL.
	std::cout << "\nscheme = " << userURL.substr(0, schemeLength);
	std::cout << "\nauthority = " << userURL.substr(schemeLength, authorityLength);
	std::cout << "\npath = " << userURL.substr(schemeLength + authorityLength, pathLength) << "\n";
}
