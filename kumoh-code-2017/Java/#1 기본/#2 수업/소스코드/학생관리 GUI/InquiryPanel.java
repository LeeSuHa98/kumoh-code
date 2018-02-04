
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.JButton;
import javax.swing.JTextArea;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class InquiryPanel extends JPanel {// �л� ��ȸ�� �г� 
	private JTextField textField;
	private JTextArea textArea;

	/*
	 * Create the panel.
	 */
	public InquiryPanel(MainFrame frame) { //�Ű������� mainframe���� ���� ������
		setBounds(0, 0,316, 262);
		setLayout(null);
		
		textField = new JTextField();
		textField.setBounds(25, 50, 108, 21);
		add(textField);
		textField.setColumns(10);
		
		JButton btnNewButton = new JButton("\uAC80\uC0C9");
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {//�л� �˻� ��ư�� �̺�Ʈ
				searchStudent(frame);
			}
		});
		btnNewButton.setBounds(145, 49, 63, 23);
		add(btnNewButton);
		
		JButton btnNewButton_1 = new JButton("\uB4A4\uB85C");
		btnNewButton_1.addActionListener(new ActionListener() {//��� ��ư�� �̺�Ʈ
			public void actionPerformed(ActionEvent e) {
				frame.getSubPanel().remove(frame.getInquiryPanel());
				frame.getSubPanel().repaint();
				frame.getSubPanel().add(frame.getMainPenel());
			}
		});
		btnNewButton_1.setBounds(220, 49, 66, 23);
		add(btnNewButton_1);
		
		textArea = new JTextArea();
		printAll(frame);
		textArea.setBounds(25, 82, 262, 170);
		add(textArea);
		
		JButton button = new JButton("\uC804\uAC80");
		button.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {//��ü��ȸ�� �̺�Ʈ
				printAll(frame);
			}
		});
		button.setBounds(25, 9, 84, 23);
		add(button);
	}
	void searchStudent(MainFrame frame)//�л� �˻� �Լ�
	{
		textArea.setText("");
		for(int i = 0; i < frame.getSlist().getCount() ; i++)
		{
			Student s = frame.getSlist().getStudents(i);
			String str = s.getName()+" "+s.getSnum()+" "+s.getJbun()+" "+s.getAddress();
			if(str.contains(textField.getText()))//�л� ������ textfiled�� ���� ���� ���� ������ true �ƴϸ� false
			{
				textArea.append(str);
				textArea.append("\n");
			}
		}
	}
	void printAll(MainFrame frame)//�л� ��ü ��ȸ �Լ�, ���Ǿ��� ���� �л���θ� ������ش�.
	{
		textArea.setText("");;
		for(int i = 0; i < frame.getSlist().getCount() ; i++)
		{
			Student s = frame.getSlist().getStudents(i);
			textArea.append(s.getName()+" "+s.getSnum()+" "+s.getJbun()+" "+s.getAddress());
			textArea.append("\n");
		}
	}
}
