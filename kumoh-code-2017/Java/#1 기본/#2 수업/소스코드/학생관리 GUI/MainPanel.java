import javax.swing.JPanel;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class MainPanel extends JPanel {// 메뉴 선택용 패널
	MainPanel mp;
	/**
	 * Create the panel.
	 */
	public MainPanel(MainFrame frame) {
		setBounds(0, 0,316, 262);
		setLayout(null);
		mp = this;
		JButton btnNewButton = new JButton("\uD559\uC0DD \uB4F1\uB85D");
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {// 학생 등록 버튼 클릭시 이벤트
				frame.getSubPanel().remove(frame.getMainPenel()); // 1.현재 패널을 지운다.
				frame.getSubPanel().repaint();					  // 2.패널을 repaint 시킨다.
				frame.getSubPanel().add(frame.getRegisterPanel());// 3.등록 패널을 추가한다.
			}
		});
		btnNewButton.setBounds(49, 61, 93, 49);
		add(btnNewButton);
		
		JButton button = new JButton("\uD559\uC0DD \uC870\uD68C");
		button.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {// 학생 조회 버튼 클릭시 이벤트
				frame.getSubPanel().remove(frame.getMainPenel());
				frame.getSubPanel().repaint();
				frame.getSubPanel().add(frame.getInquiryPanel());
			}
		});
		button.setBounds(171, 61, 93, 49);
		add(button);
		
		JButton button_1 = new JButton("\uD559\uC0DD \uC0AD\uC81C");
		button_1.setBounds(49, 147, 93, 49);
		add(button_1);
		
		JButton button_2 = new JButton("\uD559\uC0DD \uC218\uC815");
		button_2.setBounds(171, 147, 93, 49);
		add(button_2);

	}
}
