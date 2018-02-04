import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.Point;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;

public class MouseEventDemo extends JFrame {
	JLabel label1, label2;
	JButton btn1;
	public MouseEventDemo()
	{
		super("test");
		initializeComponents();
	}
	private void initializeComponents() {
		Container c = getContentPane();
		//c.setLayout(null);
		c.setLayout(new FlowLayout());
		
		btn1 = new JButton("Drag Me");
		btn1.setLocation(100, 200);
		btn1.setSize(50, 50);
		MouseEventHandler ob = new MouseEventHandler();
		btn1.addMouseMotionListener(ob);
		c.add(btn1);
		
		setSize(200, 200);
		setLocation(300, 300);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setVisible(true);      
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MouseEventDemo app = new MouseEventDemo();
	}

	//����Ŭ������ ����� ����Ŭ������ ������Ʈ ��� ����
	class MouseEventHandler implements MouseListener,MouseMotionListener{
		@Override
		public void mouseDragged(MouseEvent e) {
			// TODO Auto-generated method stub
			Point bx = btn1.getLocation();
			btn1.setLocation(bx.x + e.getX(), bx.y + e.getY());
		}
		// e.getX() �� ������� â�� �������� ��Ÿ���� ��ǥ�̸� e.getXOnScreen()�� ���� ������â�� �������� �Ѵ�.
		@Override
		public void mouseMoved(MouseEvent e) {
			// TODO Auto-generated method stub
		}
		@Override
		public void mouseClicked(MouseEvent e) {
			// TODO Auto-generated method stub
		}
		@Override
		public void mousePressed(MouseEvent e) {
			// TODO Auto-generated method stub

		}
		@Override
		public void mouseReleased(MouseEvent e) {
			// TODO Auto-generated method stub
		}
		@Override
		public void mouseEntered(MouseEvent e) {
			// TODO Auto-generated method stub
		}
		@Override
		public void mouseExited(MouseEvent e) {
			// TODO Auto-generated method stub
		}
	}
}

