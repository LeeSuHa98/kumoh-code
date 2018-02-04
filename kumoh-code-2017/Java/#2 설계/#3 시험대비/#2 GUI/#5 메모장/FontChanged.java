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
	 * 폰트설정 다이얼로
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

		super(f, "서식", false);
		this.f = f;
		this.flag = flag;
		Container co = getContentPane();
		sas = new SimpleAttributeSet();
		
		/*
		 * 리스트에 들어갈 정보를 Vector 또는 배열에 담음
		 */
		ge = GraphicsEnvironment.getLocalGraphicsEnvironment();
		Font[] arr = ge.getAllFonts();
		fontName = new Vector<String>();
		fontSize = new Vector<String>();
		styleMap = new HashMap<String, String>();
		int[] arrsty = { Font.PLAIN, Font.BOLD, Font.ITALIC};
		String[] fontStyle = { "보통", "굵게", "삐딱하게" };
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
		 * 컴포넌트 생성
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
		confirm = new JButton("확인");
		cancel = new JButton("취소");
		sampleFont = new JLabel("가나다 asdASD123");
		total = new JPanel(new BorderLayout());
		p1 = new JPanel(new BorderLayout());
		p2 = new JPanel(new BorderLayout());
		p3 = new JPanel(new BorderLayout());
		p4 = new JPanel();
		p5 = new JPanel();
		p6 = new JPanel();
		
		/*
		 * TextArea의 기본 폰트 정보를 리스트 기본 값으로 설정과
		 * 기본 리스트 크기 지정
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
		 * 컴포넌트를 Panel과 다이얼로그 창에 추가
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
		tp.add("글꼴", total);
		tp.add("색상", colorSelect);
		co.add(tp, "Center");
		co.add(p4, "South");
		
		/*
		 * Panel Border 설정
		 */
		p1.setBorder(new TitledBorder(new LineBorder(Color.black), "글꼴",
				TitledBorder.LEFT, TitledBorder.TOP));
		p2.setBorder(new TitledBorder(new LineBorder(Color.black), "글꼴 스타일",
				TitledBorder.LEFT, TitledBorder.TOP));
		p3.setBorder(new TitledBorder(new LineBorder(Color.black), "글꼴 크기",
				TitledBorder.LEFT, TitledBorder.TOP));
		p6.setBorder(new TitledBorder(new LineBorder(Color.black), "미리보기",
				TitledBorder.LEFT, TitledBorder.TOP));
		
		/*
		 * Listener 추가
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
		 * 리스트 선택시 보기글씨를 바꿈
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
		 * Text가 선택되어 있을때 실행, 선택된  부분만 변경
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
		 * Text가 선택되지 않았을때 실행, 전체 변경
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
		 * 폰트 다이얼로그 창에서 확인을 누르면
		 * 지정된 폰트속성과 색깔 속성을 변수에 저장
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