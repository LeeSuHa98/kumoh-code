
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.JButton;
import javax.swing.JTextArea;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class InquiryPanel extends JPanel {// 학생 조회용 패널 
	private JTextField textField;
	private JTextArea textArea;

	/*
	 * Create the panel.
	 */
	public InquiryPanel(MainFrame frame) { //매개변수를 mainframe으로 갖는 생성자
		setBounds(0, 0,316, 262);
		setLayout(null);
		
		textField = new JTextField();
		textField.setBounds(25, 50, 108, 21);
		add(textField);
		textField.setColumns(10);
		
		JButton btnNewButton = new JButton("\uAC80\uC0C9");
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {//학생 검색 버튼의 이벤트
				searchStudent(frame);
			}
		});
		btnNewButton.setBounds(145, 49, 63, 23);
		add(btnNewButton);
		
		JButton btnNewButton_1 = new JButton("\uB4A4\uB85C");
		btnNewButton_1.addActionListener(new ActionListener() {//취소 버튼의 이벤트
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
			public void actionPerformed(ActionEvent e) {//전체조회의 이벤트
				printAll(frame);
			}
		});
		button.setBounds(25, 9, 84, 23);
		add(button);
	}
	void searchStudent(MainFrame frame)//학생 검색 함수
	{
		textArea.setText("");
		for(int i = 0; i < frame.getSlist().getCount() ; i++)
		{
			Student s = frame.getSlist().getStudents(i);
			String str = s.getName()+" "+s.getSnum()+" "+s.getJbun()+" "+s.getAddress();
			if(str.contains(textField.getText()))//학생 정보중 textfiled의 값과 같은 값이 있으면 true 아니면 false
			{
				textArea.append(str);
				textArea.append("\n");
			}
		}
	}
	void printAll(MainFrame frame)//학생 전체 조회 함수, 조건없이 현재 학생모두를 출력해준다.
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
