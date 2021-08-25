/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Content;

import java.util.ArrayList;

import javax.swing.plaf.basic.BasicInternalFrameUI;
import javax.swing.table.DefaultTableModel;

import Models.Administrador;
import Models.Registro;
import Models.Veterinario;

/**
 *
 * @author enya
 */
public class ListarFuncionarios extends javax.swing.JInternalFrame {

    private String tipoFuncionario;
    private Registro registros;

    /**
     * Creates new form Lista
     */
    public ListarFuncionarios() {
        initComponents();
        this.setBorder(javax.swing.BorderFactory.createEmptyBorder(0, 0, 0, 0));
        BasicInternalFrameUI ui = (BasicInternalFrameUI) this.getUI();
        ui.setNorthPane(null);
        this.tipoFuncionario = "";
    }

    public ListarFuncionarios(String funcionario, Administrador adm, Registro registros) {
        initComponents();
        this.setBorder(javax.swing.BorderFactory.createEmptyBorder(0, 0, 0, 0));
        BasicInternalFrameUI ui = (BasicInternalFrameUI) this.getUI();
        ui.setNorthPane(null);
        setTipoFuncionario(funcionario);
        setRegistros(registros);
    }

    private void setRegistros(Registro registros) {
        this.registros = registros;
    }

    private Registro getRegistros() {
        return this.registros;
    }

    private void setTipoFuncionario(String tipoFuncionario) {
        this.tipoFuncionario = tipoFuncionario;
    }
    
    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        jLabel5 = new javax.swing.JLabel();
        jLabel6 = new javax.swing.JLabel();
        jScrollPane1 = new javax.swing.JScrollPane();
        jTable1 = new javax.swing.JTable();
        jSeparator1 = new javax.swing.JSeparator();

        setBackground(new java.awt.Color(240, 240, 240));

        jPanel1.setBackground(new java.awt.Color(240, 240, 240));

        jLabel5.setFont(new java.awt.Font("SansSerif", 1, 18)); // NOI18N
        jLabel5.setForeground(new java.awt.Color(41, 52, 55));
        jLabel5.setText("Visualizar vendedores");
        jLabel5.addAncestorListener(new javax.swing.event.AncestorListener() {
            public void ancestorAdded(javax.swing.event.AncestorEvent evt) {
                jLabel5AncestorAdded(evt);
            }
            public void ancestorMoved(javax.swing.event.AncestorEvent evt) {
            }
            public void ancestorRemoved(javax.swing.event.AncestorEvent evt) {
            }
        });

        jLabel6.setFont(new java.awt.Font("SansSerif", 0, 14)); // NOI18N
        jLabel6.setForeground(new java.awt.Color(41, 52, 55));
        jLabel6.setText("Visualize os vendedor cadastrados no sistema através da tabela abaixo");

        jTable1.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {
                "ID", "Nome", "Usuário", "Senha", "CPF", "Salario"
            }
        ) {
            Class[] types = new Class [] {
                java.lang.Integer.class, java.lang.String.class, java.lang.String.class, java.lang.String.class, java.lang.String.class, java.lang.String.class
            };
            boolean[] canEdit = new boolean [] {
                false, false, false, false, false, false
            };

            public Class getColumnClass(int columnIndex) {
                return types [columnIndex];
            }

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        jScrollPane1.setViewportView(jTable1);

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGap(55, 55, 55)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jLabel5)
                    .addComponent(jLabel6)
                    .addComponent(jSeparator1, javax.swing.GroupLayout.PREFERRED_SIZE, 517, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 517, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(87, Short.MAX_VALUE))
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGap(30, 30, 30)
                .addComponent(jLabel5)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jLabel6)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jSeparator1, javax.swing.GroupLayout.PREFERRED_SIZE, 10, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 366, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(62, Short.MAX_VALUE))
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jLabel5AncestorAdded(javax.swing.event.AncestorEvent evt) {// GEN-FIRST:event_jLabel5AncestorAdded
        // TODO add your handling code here:
        if (tipoFuncionario.equals("vendedor")) { //se o menu for para o tipo vendedor
            jLabel5.setText("Visualizar vendedores");
            jLabel6.setText("Visualize os vendedores cadastrados no sistema através da tabela abaixo");

            getRegistros().getVendedores();
            ArrayList<String[]> vendedores = new ArrayList<>();

            //Criando arrays e adicionado ao ArrayList para a tabela
            getRegistros().getVendedores().forEach(vendedor -> {
                String aux[] = new String[6];
                aux[0] = String.valueOf(vendedor.getId());
                aux[1] = vendedor.getNome();
                aux[2] = vendedor.getUsuario();
                aux[3] = vendedor.getSenha();
                aux[4] = vendedor.getCpf();
                aux[5] = Float.toString(vendedor.getSalario());
                vendedores.add(aux);
            });
            
            //Adicionado os dados do ArryList a tabela
            DefaultTableModel tbl = (DefaultTableModel) jTable1.getModel();
            vendedores.forEach(vendedor -> {
                tbl.addRow(vendedor);
            });

        } else if (tipoFuncionario.equals("veterinário")) { //se o menu for para o tipo veterinário
            jLabel5.setText("Visualizar veterinários");
            jLabel6.setText("Visualize os veterinários cadastrados no sistema através da tabela abaixo");

            getRegistros().getVendedores();
            ArrayList<String[]> veterinarios = new ArrayList<>();

            //Criando arrays e adicionado ao ArrayList para a tabela
            for (Veterinario veterinario : getRegistros().getVeterinarios()) {
                String aux[] = new String[6];
                aux[0] = String.valueOf(veterinario.getId());
                aux[1] = veterinario.getNome();
                aux[2] = veterinario.getUsuario();
                aux[3] = veterinario.getSenha();
                aux[4] = veterinario.getCpf();
                aux[5] = Float.toString(veterinario.getSalario());
                veterinarios.add(aux);
            }

            //Adicionado os dados do ArryList a tabela
            DefaultTableModel tbl = (DefaultTableModel) jTable1.getModel();
            for (String[] veterinario : veterinarios) {
                tbl.addRow(veterinario);
            }
        } else {
            jLabel5.setText("Visualizar !Erro(null)");
            jLabel6.setText("Erro - Tipo do funcionario não informado.");
        }

    }// GEN-LAST:event_jLabel5AncestorAdded

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JSeparator jSeparator1;
    private javax.swing.JTable jTable1;
    // End of variables declaration//GEN-END:variables
}
