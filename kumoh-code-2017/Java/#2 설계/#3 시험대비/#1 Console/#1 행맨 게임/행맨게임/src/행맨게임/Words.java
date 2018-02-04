package ��ǰ���;
import java.util.*;
import java.io.*;

//words.txt ������ �а� ���Ͽ��� �����ϰ� �ܾ �����ϴ� Ŭ����
class Words {
	final int WORDMAX = 25143; // words.txt���Ͽ� ��� �ִ� �� �ܾ��� ����
	private String fileName; // �ܾ� ���� �̸�. ����� words.txt
	private Random r = new Random(); // ���� �߻���

	public Words(String fileName) {
		this.fileName = fileName;
	}

	public String getRandomWord() {
		// ������ �б� ���� BufferedReader ��ü�� �����Ѵ�.
		BufferedReader in = null;      
		try {
			// ������ ���� ������ �б� ���� BufferedReader ��ü ����
			in = new BufferedReader(new FileReader(fileName));
		}
		catch(FileNotFoundException e) {
			System.out.println("file not found error");
			System.exit(0);
		}
		int n = r.nextInt(WORDMAX); // ������ ���� ��ȣ ����. n ��° �ܾ ���ӿ� ���
		return readWord(in, n); // in ���Ͽ��� n ��° ������ �ܾ �о ����
	}

	// in ���Ͽ��� n ��° ������ �ܾ �о� �����ϴ� �޼ҵ�
	private String readWord(BufferedReader in, int n) {
		String line=null; // �� ������ ������ ���ڿ� ��ü. �� ���ο��� �ϳ��� �ܾ ����
		try {
			while (n>0) {
				line = in.readLine(); // ���Ͽ��� �� ����(�� �ܾ�)�� �д´�.
				if(line == null) // eof�� ������ ���� �߻�. ���� ����
					break;
				n--;
			}
		} catch (IOException e) {
			System.exit(0);
		}
		return line; // n ��° ������ �ܾ� ����
	}
}