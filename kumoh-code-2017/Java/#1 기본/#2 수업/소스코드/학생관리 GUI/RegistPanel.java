import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class RegistPanel extends JPanel { // �л� ��� �г�
	private JTextField textField;
	private JTextField textField_1;
	private JTextField textField_2;
	private JTextField textField_3;

	/**
	 * Create the panel.
	 */
	public RegistPanel(MainFrame frame) {
		setBounds(0, 0,316, 262);
		setLayout(null);
		
		JLabel label = new JLabel("\uC774\uB984");
		label.setBounds(44, 41, 33, 15);
		add(label);
		
		JLabel label_1 = new JLabel("\uD559\uBC88");
		label_1.setBounds(44, 88, 33, 15);
		add(label_1);
		
		JLabel label_2 = new JLabel("\uC804\uBC88");
		label_2.setBounds(44, 139, 33, 15);
		add(label_2);
		
		JLabel label_3 = new JLabel("\uC8FC\uC18C");
		label_3.setBounds(44, 186, 33, 15);
		add(label_3);
		
		textField = new JTextField();
		textField.setBounds(100, 38, 116, 21);
		add(textField);
		textField.setColumns(10);
		
		textField_1 = new JTextField();
		textField_1.setColumns(10);
		textField_1.setBounds(100, 85, 116, 21);
		add(textField_1);
		
		textField_2 = new JTextField();
		textField_2.setColumns(10);
		textField_2.setBounds(100, 136, 116, 21);
		add(textField_2);
		
		textField_3 = new JTextField();
		textField_3.setColumns(10);
		textField_3.setBounds(100, 183, 116, 21);
		add(textField_3);
		
		JButton btnNewButton = new JButton("\uB4F1\uB85D");
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Student student = new Student(textField.getText(),
						Integer.parseInt(textField_1.getText()),
						textField_2.getText(), textField_3.getText());//Student ��ü�� �ؽ�Ʈ �ʵ� �װ��� ���� �����ڸ� ���� ���� 
				frame.getSlist().insertStd(student);//�л� ����Ʈ�� ������ ���� �л� ��ü�� �߰��Ѵ�
				frame.getSubPanel().remove(frame.getRegisterPanel());//���� ȭ���� �޴� ����ȭ������ �̵�
				frame.getSubPanel().repaint();
				frame.getSubPanel().add(frame.getMainPenel());
			}
		});
		btnNewButton.setBounds(228, 112, 60, 41);
		add(btnNewButton);
		
		JButton button = new JButton("\uCDE8\uC18C");
		button.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				frame.getSubPanel().remove(frame.getRegisterPanel());
				frame.getSubPanel().repaint();
				frame.getSubPanel().add(frame.getMainPenel());
			}
		});
		button.setBounds(228, 163, 60, 41);
		add(button);
	}
}
