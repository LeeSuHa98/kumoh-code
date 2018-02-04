import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;

public class MainFrame extends JFrame {//각 서브패널을 포함하고 있는 메인 프레임

	private JPanel contentPane; //패널 교체용 패널
	private StudentList sList = new StudentList();
	JPanel subPanel; //패널 교체시 사용하는 임시 패널
	MainPanel mp; // mp ip rp 미리 선언한 세부 패널
	InquiryPanel ip;
	RegistPanel rp;
	
	public StudentList getSlist(){return sList;}
	public RegistPanel getRegisterPanel(){return rp;}
	public MainPanel getMainPenel(){return mp;};
	public JPanel getSubPanel(){return subPanel;}
	public InquiryPanel getInquiryPanel(){return ip;}
	
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					MainFrame frame = new MainFrame();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public MainFrame() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 356, 357);
		
		mp = new MainPanel(this);
		rp = new RegistPanel(this);
		ip = new InquiryPanel(this);
		
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JLabel lblNewLabel = new JLabel("\uD559\uC0DD\uAD00\uB9AC\uD504\uB85C\uADF8\uB7A8");
		lblNewLabel.setBounds(115, 22, 106, 15);
		contentPane.add(lblNewLabel);
		subPanel = new JPanel();
		subPanel.setLayout(null);
		subPanel.add(mp); //첫 시작은 main panel 부터 시작
		subPanel.setBounds(12, 47, 316, 262);
		contentPane.add(subPanel); 
	}
}
