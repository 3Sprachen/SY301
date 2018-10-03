#include <iostream>
#include <stdio.h>

using namespace std;


class Process{
public:
    char* name;
    int memoryReq;
    Process (char*, int);
    void Print();
};

Process::Process(char* a, int b){
  name = a;
  memoryReq = b;
}
void Process::Print(){
  cout << "\nProcess name: " << name << "\n" << "Memory Required: "<< memoryReq << "\n" << endl;
  //return name; //?
  //return memoryReq; //?
}

class Machine{
  private:
    char* name;
    char ** proc;
    int totalMem;
    int availMem;
    int count; //keep track of nuumber of processes

  public:
    Machine(char*, char **, int);
    void AddProcess(Process);
    int AvailableMemory(Process);
    void Print();
};
Machine::Machine(char* a, char** b, int c){
  name = a;
  proc = b;
  totalMem = c;
  count = 0;
}
void Machine::AddProcess(Process P){//should this argument be an instance of process funcion?
  proc[count] = P.name;
  count++;
}
int Machine::AvailableMemory(Process P){//may take Process as argument
  availMem = totalMem - P.memoryReq;
  return availMem;
}
void Machine::Print(){
  cout << "Machine Name: " << name << "\n" << "Total machine memory: " << totalMem << "\n" << "Available memory: " << availMem << "\n" << endl;
  cout << "Running Processes:\n" << proc[0] << "\n" <<  proc[1] << "\n" << endl;
}
int main(){

char Process_Name[100];
char Machine_Name[100];
int Process_Memory;
int Machine_Memory;
char *Process_List[100];

cout << "Enter Process Name" << endl;
cin >> Process_Name;
cout << "Enter Process Memory" << endl;
cin >> Process_Memory;
cout << "Enter Machine Name" << endl;
cin >> Machine_Name;
cout << "Enter total Machine Memory" << endl;
cin >> Machine_Memory;

Process P(Process_Name, Process_Memory);
Machine M(Machine_Name, Process_List, Machine_Memory);

P.Print();
M.AddProcess(P);
M.AddProcess(P); 	// We will add the same process twice so we can have two things in our process list
M.AvailableMemory(P);
M.Print();

return 0;
}
