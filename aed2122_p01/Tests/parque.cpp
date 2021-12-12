#include "parque.h"
#include <vector>

using namespace std;

ParqueEstacionamento::ParqueEstacionamento(unsigned lot, unsigned nMaxCli):lotacao(lot), numMaximoClientes(nMaxCli){
    this->clientes={};
    this->vagas=lotacao;
}
unsigned ParqueEstacionamento::getNumLugares() const{
    return lotacao;
}

unsigned ParqueEstacionamento::getNumMaximoClientes() const{
    return numMaximoClientes;
}

int ParqueEstacionamento::posicaoCliente(const string & nome) const {
    for (int i = 0; i < clientes.size(); i++) {
        if (clientes[i].nome == nome)
            return i;
        else
            return -1;
    }
}

bool ParqueEstacionamento::adicionaCliente(const string & nome){
    if(clientes.size()==numMaximoClientes){
        return false;
    }
    InfoCartao info;
    info.nome=nome;
    info.presente = false;
    clientes.push_back(info);
    return true;

}
bool ParqueEstacionamento::entrar(const string & nome){
    if(clientes.size()==numMaximoClientes || posicaoCliente(nome)==-1 || clientes[posicaoCliente(nome)].presente==false){
        return false;
    }
    clientes[posicaoCliente(nome)].presente=true;
    vagas --;
    return true;
}

bool ParqueEstacionamento::retiraCliente(const string & nome){
    for (vector<InfoCartao>::iterator it = clientes.begin(); it != clientes.end(); it++)
        if ( (*it).nome == nome ) {
            if (!(*it).presente) {
                clientes.erase(it);
                return true;
            }
            else return false;
        }
    return false;
}

bool ParqueEstacionamento::sair(const string &nome) {
    if (posicaoCliente(nome) == -1)
        return false;
    if (!clientes[posicaoCliente(nome)].presente)
        return false;
    clientes[posicaoCliente(nome)].presente = false;
    vagas ++;
    return true;
}

unsigned ParqueEstacionamento::getNumLugaresOcupados() const{
    return lotacao-vagas;
}
unsigned ParqueEstacionamento::getNumClientesAtuais() const{
    return clientes.size();
}
