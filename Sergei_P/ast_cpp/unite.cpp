#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
extern "C" {
	void drop_buf();
	int yyparse();
}

extern std::ostringstream* mirror();

struct Node {
	std::string Name;
	long Count;
	std::string Value;
	std::vector<std::string> Template;
	std::vector<Node> Inner;
};

std::vector<std::string> result;

void Nodetree(std::vector<Node> &q, int a=0) {	
	for (Node t : q) {
		std::ostringstream xmlstr;
		xmlstr << std::string(a, '\t') << "<" << t.Name << " type=\"" << ((t.Count!=-1)?"rule":"token") << "\" value=\"" << t.Value << "\">";
		result.push_back(xmlstr.str());
		if (t.Count!=-1) {
			Nodetree(t.Inner,a+1);
		}
		xmlstr.str("");
		xmlstr << std::string(a, '\t') << "</" << t.Name << ">";
		result.push_back(xmlstr.str());		
	}
}

extern FILE *yyin;

void parse(std::string inf, std::string ouf) {
	yyin = fopen(inf.c_str(), "r"); yyparse();
	std::string s=mirror()->str(); drop_buf();
	result.clear();
	std::vector<std::string> parts;
	std::vector<Node> nodes;
	boost::algorithm::split(parts, s, boost::is_any_of("+"));
	for (auto t : parts) { if (t!="") {
		t=t.substr(1,t.length()-2);		
		std::vector<std::string> subparts;
		boost::algorithm::split(subparts, t, boost::is_any_of(","));
		std::string name=subparts[0];
		long count=std::stol(subparts[1]);
		std::string rule=subparts[2];
		Node n;
		if(count==-1) {
			n.Name=name; n.Count=count; n.Value=rule.find(">[")==0?rule.substr(2):"";
		} else if (rule!="") {
			auto trunc=rule.find("|");
			if (trunc==std::string::npos) {
				trunc=rule.find(":");
			}
			if (trunc==std::string::npos) {
				std::cout << rule;
			}
			rule=rule.substr(trunc+1);
			boost::replace_all(rule, "\t", " ");
			boost::algorithm::trim(rule);
			std::vector<std::string> subrules;
			boost::algorithm::split(subrules, rule, boost::is_any_of(" "));
			n.Name=name; n.Count=count; n.Value=""; n.Template=subrules;
		}
		nodes.push_back(n);
	}}
	long unsigned i=0;
	while (true) {
		auto l=nodes[i].Count;
		if (l>0) {
									
			for (int j=i-l; j>=0; j--) {
				bool found=false;
				if (nodes[i].Template[0]==nodes[j].Name) {
					found=true;
					for (int k=1; k<l; k++) {
						if(nodes[j+k].Name!=nodes[i].Template[k]){
							found=false;
							break;
						}
					}
				}
				if (found) {
					for (int k=0; k<l; k++) {
						nodes[i].Inner.push_back(nodes[j+k]);
					}
					nodes[i].Count=0;
					
					nodes.erase(nodes.begin()+j,nodes.begin()+j+l);
					i-=l;
					nodes.insert(nodes.begin() + j, nodes[i]);
					nodes.erase(nodes.begin() + i + 1);
										
					i=0;
					break;
				}
			}
		}
		i++;
		if (i>nodes.size()) break;
	}
	Nodetree(nodes);
	
	std::ofstream xmlf;
	xmlf.open (ouf);
	for (auto t : result) xmlf << t << std::endl;
	xmlf.close();
}

extern "C" void parse_c(const char* fn1, const char* fn2) {
	parse(std::string(fn1),std::string(fn2));
}

/*
int main() {
	parse("test.i","test.xml");
}
*/
