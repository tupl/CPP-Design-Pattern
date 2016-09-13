#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <unordered_map>
#include <vector>

struct Node {
	std::string tag;
	std::vector<std::pair<std::string, std::string>> attributes;
	std::vector<Node*> children;
	std::string message;
};

void xml_element(Node* n, std::string& result);
void xml_tag(Node* n, std::string& result);
void xml_attributes(Node* n, std::string& result);

std::unordered_map<std::string, std::string>
	_map;

void xml_element(Node* n, std::string& result) {
	xml_tag(n, result);
	xml_attributes(n, result);
	result += "0 ";
	std::vector<Node*> children = n->children;
	for(int i = 0; i < children.size(); ++i) {
		xml_element(children[i], result);
	}
	if ((n->message).size()) {
		result += n->message + " ";
	}
	result += "0 ";
}

void xml_tag(Node* n, std::string& result) {
	result += _map[n->tag] + " ";
}

void xml_attributes(Node* n, std::string& result) {
	std::vector<std::pair<std::string, std::string>>
		attributes = n->attributes;
	for(int i = 0; i < attributes.size(); ++i) {
		result += _map[attributes[i].first] + " ";
		result += attributes[i].second + " ";
	}
}

void mapping_init() {
	_map["family"] = "1";
	_map["person"] = "2";
	_map["firstName"] = "3";
	_map["lastName"] = "4";
	_map["state"] = "5";
}

int main() {
	mapping_init();

	Node* family = new Node;
	family->tag = "family";
	(family->attributes).push_back({"lastName", "McDowell"});
	(family->attributes).push_back({"state", "CA"});

	Node* person = new Node;
	(person->attributes).push_back({"firstName", "Gayle"});
	person->message = "Some Message";

	(family->children).push_back(person);

	std::string result;
	xml_element(family,result);
	std::cout << result << std::endl;
	return 0;
}