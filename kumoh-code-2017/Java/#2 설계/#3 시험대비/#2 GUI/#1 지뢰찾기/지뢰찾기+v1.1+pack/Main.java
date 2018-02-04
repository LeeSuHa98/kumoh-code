import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Main extends JFrame {
	Toolkit tk=Toolkit.getDefaultToolkit();
	Dimension screen=tk.getScreenSize(); // ȭ���� ũ�⸦ ����
	JButton restart;
	static Main mineSweeper;
	static Field field;
	static JLabel label;
	
	public Main(String title, int width, int height) { // Main ������
		super(title);
		setSize(width, height);
		setLocation((screen.width-width)/2, (screen.height-height)/2);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLayout(null);
		setResizable(false);
		
		field=new Field(300, 300);
		
		restart=new JButton("�����");
		restart.setSize(100, 25);
		restart.setLocation(5, 2);
		restart.addMouseListener(new MouseAdapter() { // mouseAdapter �߰�
			public void mouseClicked(MouseEvent me) { // override
				Main.label.setText("");
				Field.isSuccess=true;
				mineSweeper.getContentPane().remove(field);
				field=new Field(300, 300);
				mineSweeper.getContentPane().add(field);
				mineSweeper.getContentPane().invalidate();
				mineSweeper.getContentPane().validate();
			}
		});
		
		label=new JLabel("", JLabel.RIGHT);
		
		label.setSize(100, 25);
		label.setLocation(195, 2);
		
		add(field);
		add(restart);
		add(label);
		setVisible(true);
		
	} // ������
	public static void main(String[] args) { // main
		mineSweeper=new Main("����ã��", 306, 360);
	} // �޼���
} // Ŭ����