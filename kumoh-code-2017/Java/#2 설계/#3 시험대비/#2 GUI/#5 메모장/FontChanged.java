import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.Font;
import java.awt.GraphicsEnvironment;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.HashMap;
import java.util.Vector;
import javax.swing.JButton;
import javax.swing.JColorChooser;
import javax.swing.JDialog;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTabbedPane;
import javax.swing.JTextField;
import javax.swing.border.LineBorder;
import javax.swing.border.TitledBorder;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;
import javax.swing.text.SimpleAttributeSet;
import javax.swing.text.StyleConstants;

public class FontChanged extends JDialog implements ListSelectionListener, ActionListener{
	
	/*
	 * ��Ʈ���� ���̾��
	 */

	JPanel p1, p2, p3, p4, p5, p6, total;

	JLabel sampleFont;

	JTextField tFont, tStyle, tSize;

	JList lFont, lStyle, lSize;

	JButton confirm, cancel;

	GraphicsEnvironment ge;

	JScrollPane fontPane, stylePane, sizePane;

	JTabbedPane tp;

	JColorChooser colorSelect;

	Vector<String> fontName;

	Vector<String> fontSize;

	HashMap<String, String> styleMap;
	
	String font;

	Color color;

	NotePad f;

	SimpleAttributeSet sas;

	int flag;

	int style;

	int size;

	FontChanged(NotePad f, int flag) {

		super(f, "����", false);
		this.f = f;
		this.flag = flag;
		Container co = getContentPane();
		sas = new SimpleAttributeSet();
		
		/*
		 * ����Ʈ�� �� ������ Vector �Ǵ� �迭�� ����
		 */
		ge = GraphicsEnvironment.getLocalGraphicsEnvironment();
		Font[] arr = ge.getAllFonts();
		fontName = new Vector<String>();
		fontSize = new Vector<String>();
		styleMap = new HashMap<String, String>();
		int[] arrsty = { Font.PLAIN, Font.BOLD, Font.ITALIC};
		String[] fontStyle = { "����", "����", "�ߵ��ϰ�" };
		for (int i = 0; i < arr.length; i++) {
			fontName.add(arr[i].getFontName());
		}
		for (int i = 0; i < arrsty.length; i++) {
			styleMap.put(fontStyle[i], arrsty[i] + "");
		}
		for (int i = 6, j = 0; i < 100; i = i + 2, j++) {
			fontSize.add(i + "");
		}
		
		/*
		 * ������Ʈ ����
		 */
		colorSelect = new JColorChooser();
		tp = new JTabbedPane();
		tFont = new JTextField();
		tStyle = new JTextField();
		tSize = new JTextField();
		lFont = new JList(fontName);
		lStyle = new JList(fontStyle);
		lSize = new JList(fontSize);
		fontPane = new JScrollPane(lFont);
		stylePane = new JScrollPane(lStyle);
		sizePane = new JScrollPane(lSize);
		confirm = new JButton("Ȯ��");
		cancel = new JButton("���");
		sampleFont = new JLabel("������ asdASD123");
		total = new JPanel(new BorderLayout());
		p1 = new JPanel(new BorderLayout());
		p2 = new JPanel(new BorderLayout());
		p3 = new JPanel(new BorderLayout());
		p4 = new JPanel();
		p5 = new JPanel();
		p6 = new JPanel();
		
		/*
		 * TextArea�� �⺻ ��Ʈ ������ ����Ʈ �⺻ ������ ������
		 * �⺻ ����Ʈ ũ�� ����
		 */
		Font fo = f.ta.getFont();
		Color breco = f.ta.getForeground();
		colorSelect.setColor(breco);
		lFont.setFixedCellHeight(15);
		lFont.setFixedCellWidth(150);
		lStyle.setFixedCellHeight(15);
		lStyle.setFixedCellWidth(70);
		lSize.setFixedCellHeight(15);
		lSize.setFixedCellWidth(40);
		lFont.setSelectedValue(fo.getFontName(), true);
		lStyle.setSelectedIndex(fo.getStyle());
		lSize.setSelectedValue(fo.getSize() + "", true);
		tFont.setText((String) lFont.getSelectedValue());
		tStyle.setText((String) lStyle.getSelectedValue());
		tSize.setText((String) lSize.getSelectedValue());
		
		/*
		 * ������Ʈ�� Panel�� ���̾�α� â�� �߰�
		 */
		p1.add(tFont, "North");
		p1.add(fontPane, "Center");
		p2.add(tStyle, "North");
		p2.add(stylePane, "Center");
		p3.add(tSize, "North");
		p3.add(sizePane, "Center");
		p4.add(confirm);
		p4.add(cancel);
		p5.add(p1);
		p5.add(p2);
		p5.add(p3);
		p6.add(sampleFont);
		total.add(p5, "Center");
		total.add(p6, "South");
		tp.add("�۲�", total);
		tp.add("����", colorSelect);
		co.add(tp, "Center");
		co.add(p4, "South");
		
		/*
		 * Panel Border ����
		 */
		p1.setBorder(new TitledBorder(new LineBorder(Color.black), "�۲�",
				TitledBorder.LEFT, TitledBorder.TOP));
		p2.setBorder(new TitledBorder(new LineBorder(Color.black), "�۲� ��Ÿ��",
				TitledBorder.LEFT, TitledBorder.TOP));
		p3.setBorder(new TitledBorder(new LineBorder(Color.black), "�۲� ũ��",
				TitledBorder.LEFT, TitledBorder.TOP));
		p6.setBorder(new TitledBorder(new LineBorder(Color.black), "�̸�����",
				TitledBorder.LEFT, TitledBorder.TOP));
		
		/*
		 * Listener �߰�
		 */
		lFont.addListSelectionListener(this);
		lStyle.addListSelectionListener(this);
		lSize.addListSelectionListener(this);
		confirm.addActionListener(this);
		cancel.addActionListener(this);

		setLocation(700, 200);
		pack();
		setVisible(true);
	}

	public void valueChanged(ListSelectionEvent e) {
		
		/*
		 * ����Ʈ ���ý� ����۾��� �ٲ�
		 */
		font = (String) lFont.getSelectedValue();
		String sstyle = (String) lStyle.getSelectedValue();
		String ssize = lSize.getSelectedValue() + "";
		tFont.setText(font);
		tStyle.setText(sstyle);
		tSize.setText(ssize);
		style = Integer.parseInt(styleMap.get(sstyle));
		size = Integer.parseInt(ssize);
		Font allFont = new Font(font, style, size);
		sampleFont.setFont(allFont);
	}

	public void selectionFontEdit() {
		
		/*
		 * Text�� ���õǾ� ������ ����, ���õ�  �κи� ����
		 */
		StyleConstants.setForeground(sas, color);
		StyleConstants.setFontFamily(sas, font);
		StyleConstants.setFontSize(sas, size);
		switch (style) {
			case 0:
				StyleConstants.setBold(sas, false);
				StyleConstants.setItalic(sas, false);
				break;
			case 1:
				StyleConstants.setBold(sas, true);
				break;
			case 2:
				StyleConstants.setItalic(sas, true);
				break;
		}
		f.sd.setCharacterAttributes(f.start, f.leng, sas, true);
	}

	public void allFontEdit() {
		
		/*
		 * Text�� ���õ��� �ʾ����� ����, ��ü ����
		 */
		f.ta.setForeground(color);
		Font allFont = new Font(font, style, size);
		f.ta.setFont(allFont);
		StyleConstants.setForeground(sas, color);
		StyleConstants.setFontFamily(sas, font);
		StyleConstants.setFontSize(sas, size);
		switch (style) {
			case 0:
				StyleConstants.setBold(sas, false);
				StyleConstants.setItalic(sas, false);
				break;
			case 1:
				StyleConstants.setBold(sas, true);
				break;
			case 2:
				StyleConstants.setItalic(sas, true);
				break;
		}
		f.sd.setCharacterAttributes(0, f.ta.getText().length(), sas, true);
	}

	public void actionPerformed(ActionEvent e) {
		
		/*
		 * ��Ʈ ���̾�α� â���� Ȯ���� ������
		 * ������ ��Ʈ�Ӽ��� ���� �Ӽ��� ������ ����
		 */
		if (e.getActionCommand().equals(confirm.getText())) {
			font = (String) lFont.getSelectedValue();
			style = Integer.parseInt(styleMap.get(lStyle.getSelectedValue()));
			size = Integer.parseInt((String) lSize.getSelectedValue());
			color = colorSelect.getColor();
			if (flag == 0) {
				selectionFontEdit();
			}
			else {
				allFontEdit();
			}
		}
		setVisible(false);
	}
}