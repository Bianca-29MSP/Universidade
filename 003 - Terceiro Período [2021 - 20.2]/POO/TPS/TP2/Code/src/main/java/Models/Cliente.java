/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Models;

/**
 *
 * @author thayn
 */


public class Cliente {
    private static int INIT_ID = 0;
    private int id;
    private String nome;
    private String endereco;
    
    public Cliente(String nome, String endereco){
        setId();
        setNome(nome);
        setEndereco(endereco);
    }

    public int getId() {
        return id;
    }

    public void setId() {
        this.id = ++INIT_ID;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getEndereco() {
        return endereco;
    }

    public void setEndereco(String endereco) {
        this.endereco = endereco;
    }
}
