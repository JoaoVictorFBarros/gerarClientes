#include <iostream> 
#include <random>
#include <time.h>
using namespace std;

string newName (){	
	string firstNames[20], midNames[10], lastNames[10];
	
	//Os nomes abaixo foram retirados da lista de noomes e sobrenomes mais comuns no Brasil no senso de 2010 do IBGE
	
	firstNames[0] = "Jose";
	firstNames[1] = "Maria";
	firstNames[2] = "Joao";
	firstNames[3] = "Ana";
	firstNames[4] = "Antonio";
	firstNames[5] = "Francisca";
	firstNames[6] = "Francisco";
	firstNames[7] = "Antonia";
	firstNames[8] = "Carlos";
	firstNames[9] = "Adriana";
	firstNames[10] = "Paulo";
	firstNames[11] = "Juliana";
	firstNames[12] = "Pedro";
	firstNames[13] = "Marcia";
	firstNames[14] = "Lucas";
	firstNames[15] = "Fernanda";
	firstNames[16] = "Luiz";
	firstNames[17] = "Patricia";
	firstNames[18] = "Marcos";
	firstNames[19] = "Aline";
	
	midNames[0] = "Almeida";
	midNames[1] = "Alves";
	midNames[2] = "Andrade";
	midNames[3] = "Barbosa";
	midNames[4] = "Barros";
	midNames[5] = "Batista";
	midNames[6] = "Borges";
	midNames[7] = "Campos";
	midNames[8] = "Cardoso";
	midNames[9] = "Carvalho";
	
	lastNames[0] = "Castro";
	lastNames[1] = "Costa";
	lastNames[2] = "Dias";
	lastNames[3] = "Duarte";
	lastNames[4] = "Freitas";
	lastNames[5] = "Fernandes";
	lastNames[6] = "Ferreira";
	lastNames[7] = "Garcia";
	lastNames[8] = "Gomes";
	lastNames[9] = "Goncalves";
	
	int FName, MName, LName;
	
	FName = rand()%20;
	MName = rand()%10;
	LName = rand()%10;
	
	string fullName;
	
	fullName = firstNames[FName] + " ";
	fullName = fullName + midNames[MName] + " ";
	fullName = fullName + lastNames[LName];

	return fullName;	
}

string newCPF (){
	string cpf;
	
	for (int i=0;i<11;i++){
		cpf.push_back(rand()%10 + 48);
	}
	
	return cpf;
}

string newAge (){
	string age = to_string(rand()%82 + 18);	
	return age;
}

class client {
	private:
		string name;
		string age;
		string CPF;
		
	public:
		client (){
			name = newName();
			age = newAge();
			CPF = newCPF();
		}
		void print(){
			cout<<CPF<<"\n"<<name<<"\n"<<age<<"\n\n";
		}
		void save(){
			FILE *f;
			f = fopen ("clients.txt","a+");
			string data = CPF + "\n" + name + "\n" + age + "\n\n";
			
			char aux[1000];
			int cont=0;
			
			for (int i=0;i<data.length();i++){
				aux[i] = data[i];
				cont++;
			}
			aux[cont] = '\0';			
			
			fputs(aux,f);
			fclose(f);
		}
};

int main (){
	srand(time(NULL));
	client c[1000];
	
	for (int i=0;i<1000;i++){
		c[i].print();
		c[i].save();
	}	
	return 0;
}
