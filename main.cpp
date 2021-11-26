//#include <concord/core>
//#include <concord/hdls>
#include <string>
#include <iostream>
#include <fstream>

/** parse args */
int pa(std::string const& s) {
  if (s == "spawn") return 0;
  if (s == "kill") return 1;
}

std::string read() {
  std::fstream wf;
  std::string s;
  wf.open("active.txt");
  wf >> s;
  wf.close();
  return s;
}

void rmv(std::string t) {
  std::string s = read();
  std::cout << s.find(t, t.size());
  s.erase(s.find(t), t.size()+1);
  std::cout << s << '\n';
  std::ofstream nf("active.txt");
  nf << s;
  nf.close();
}

void add(std::string s) {
  std::string o = read();
  o = o+s+'+';
  std::ofstream nf("active.txt");
  nf << o;
  nf.close();
}


/** spawn */
int spawn() {
  add("1234");
  return 1234;
}

/** kill */
void kill(std::string t) {
  rmv(t);
}

int main(int argc, char *arg[]) {
  std::string s;
  int c;
  try {
    s = arg[1];
    c = pa(s);
  } catch (...) {
    std::cout << "no command\n";
    return -1;
  }
  switch (c) {
    case 0: // spawn
      std::cout << "Spawning => port ";
      std::cout << spawn() << "\n";
      break;
    case 1: // kill
      std::cout << "Killing port " << arg[2] << '\n';
      kill(arg[2]);
      break;
    default:
      std::cout << "no command\n";
      return -1;
  }
  return 0;
}
