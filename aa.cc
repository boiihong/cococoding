#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class page {
private:

	string head_start_tok = "<head>";
	string head_end_tok = "</head>";
	string body_start_tok = "<body>";
	string body_end_tok = "</body>";
	string url_start_tok = "<meta property=\"og:url\" content=\"https://";
	string url_end_tok = "\"/>";
	string href_start_tok = "<a href=https://";
	string href_end_tok = "\" >";

	pair<size_t, size_t> find_contents(string &str, string &start, string &end) {
		size_t start_pos = str.find(start);
		size_t end_pos = str.find(end);

		return pair<size_t, size_t>(start_pos + start.size(), end_pos - start_pos - start.size());
	}

public:

	string url;
	string body;
	map<string, int> link;

	void parse_url(string &str) {
		pair<size_t, size_t> head_pos = find_contents(str, head_start_tok, head_end_tok);
		string head_contents = str.substr(head_pos.first, head_pos.second);
		pair<size_t, size_t> url_pos = find_contents(head_contents, url_start_tok, url_end_tok);
		url = head_contents.substr(url_pos.first, url_pos.second);
		cout << url << endl;
	}

	void parse_body(string &str) {
		pair<size_t, size_t> body_pos = find_contents(str, body_start_tok, body_end_tok);
		string body_contents = str.substr(body_pos.first, body_pos.second);
		cout << " body contents : " << endl;
		cout << body_contents << endl;

		// remove other tag nodes .. 
		
		// tokenize 

		// convert to lowcase

		// compare
	}

};

int solution(string word, vector<string> pages) {
	int answer = 0;

	for (int i = 0; i < pages.size(); i++) {

		int basic_score = 0;
		page this_page;
		this_page.parse_url(pages[i]);
		this_page.parse_body(pages[i]);
	}

	return answer;
}


int main(void) {
	vector<string> page = { "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>" };
	string word = "blind";

	//vector<string> page = { "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://careers.kakao.com/interview/list\"/>\n</head>  \n<body>\n<a href=\"https://programmers.co.kr/learn/courses/4673\"></a>#!MuziMuzi!)jayg07con&&\n\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://www.kakaocorp.com\"/>\n</head>  \n<body>\ncon%\tmuzI92apeach&2<a href=\"https://hashcode.co.kr/tos\"></a>\n\n\t^\n</body>\n</html>" };
	//string word = "Muzi";


	cout << solution(word, page) << endl;
	return 0;
}

