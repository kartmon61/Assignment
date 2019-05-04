package Assignment_5;

import java.awt.EventQueue;

import javax.swing.JFrame;
import java.awt.GridLayout;
import java.awt.BorderLayout;
import javax.swing.JTextField;
import java.awt.Dimension;
import javax.swing.JPanel;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class calculator {

	private JFrame frame;
	private JTextField textOutput;
	private JPanel panel;
	private JButton btnDelete;
	private JButton btnClear;
	private JButton btnMod;
	private JButton btnPlus;
	private JButton btnOne;
	private JButton btnTwo;
	private JButton btnThree;
	private JButton btnMinus;
	private JButton btnFour;
	private JButton btnFive;
	private JButton btnSix;
	private JButton btnmulti;
	private JButton btnSeven;
	private JButton btnEight;
	private JButton btnNine;
	private JButton btnDivide;
	private JButton btnZero;
	private JButton btnPoint;
	private JButton btnRoot;
	private JButton btnResult;
	
	//define Thread
	Thread calculate;
	static String number ="";
	String save;
	String operator;
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					calculator window = new calculator();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public calculator() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.setPreferredSize(new Dimension(100, 100));
		frame.setBounds(100, 100, 450, 300);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(new BorderLayout(0, 0));
		
		textOutput = new JTextField();
		textOutput.setPreferredSize(new Dimension(10, 30));
		frame.getContentPane().add(textOutput, BorderLayout.NORTH);
		textOutput.setColumns(10);
		
		panel = new JPanel();
		frame.getContentPane().add(panel, BorderLayout.CENTER);
		panel.setLayout(new GridLayout(5,4));
		
		
		
		
		
		btnDelete = new JButton("<-");
		//When the button <- click
		btnDelete.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				//define Thread and start <- button function
				calculate= new Thread(new Calculate('<'));
				calculate.start();
			}
		});
		panel.add(btnDelete);
		
		btnClear = new JButton("C");
		//When the button C click
		btnClear.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				//define Thread and start C button function
				calculate= new Thread(new Calculate('C'));
				calculate.start();
			}
		});
		panel.add(btnClear);
		
		btnMod = new JButton("%");
		//When the button % click
		btnMod.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				//define Thread and start % button function
				calculate= new Thread(new Calculate('%'));
				calculate.start();
			}
		});
		panel.add(btnMod);
		
		btnPlus = new JButton("+");
		//When the button + click
		btnPlus.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				//define Thread and start + button function
				calculate= new Thread(new Calculate('+'));
				calculate.start();
			}
		});
		panel.add(btnPlus);
		
		btnOne = new JButton("1");
		//When the button 1 click
		btnOne.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				//define Thread and start 1 button function
				calculate= new Thread(new Calculate('1'));
				calculate.start();
				
			}
		});
		panel.add(btnOne);
		
		btnTwo = new JButton("2");
		//When the button 2 click
		btnTwo.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				//define Thread and start 2 button function
				calculate= new Thread(new Calculate('2'));
				calculate.start();
			}
		});
		panel.add(btnTwo);
		
		btnThree = new JButton("3");
		//When the button 3 click
		btnThree.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				//define Thread and start 3 button function
				calculate= new Thread(new Calculate('3'));
				calculate.start();
			}
		});
		panel.add(btnThree);
		
		btnMinus = new JButton("-");
		//When the button - click
		btnMinus.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				//define Thread and start - button function
				calculate= new Thread(new Calculate('-'));
				calculate.start();
			}
		});
		panel.add(btnMinus);
		
		btnFour = new JButton("4");
		//When the button 4 click
		btnFour.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				//define Thread and start 4 button function
				calculate= new Thread(new Calculate('4'));
				calculate.start();
				
			}
		});
		panel.add(btnFour);
		
		btnFive = new JButton("5");
		//When the button 5 click
		btnFive.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				//define Thread and start 5 button function
				calculate= new Thread(new Calculate('5'));
				calculate.start();
				
			}
		});
		panel.add(btnFive);
		
		btnSix = new JButton("6");
		//When the button 6 click
		btnSix.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				//define Thread and start 6 button function
				calculate= new Thread(new Calculate('6'));
				calculate.start();
				
			}
		});
		panel.add(btnSix);
		
		btnmulti = new JButton("*");
		//When the button * click
		btnmulti.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				//define Thread and start * button function
				calculate= new Thread(new Calculate('*'));
				calculate.start();
			}
		});
		panel.add(btnmulti);
		
		btnSeven = new JButton("7");
		//When the button 7 click
		btnSeven.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				//define Thread and start 7 button function
				calculate= new Thread(new Calculate('7'));
				calculate.start();
				
				
			}
		});
		panel.add(btnSeven);
		
		btnEight = new JButton("8");
		//When the button 8 click
		btnEight.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				//define Thread and start 8 button function
				calculate= new Thread(new Calculate('8'));
				calculate.start();
			}
		});
		panel.add(btnEight);
		
		btnNine = new JButton("9");
		//When the button 9 click
		btnNine.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				//define Thread and start 9 button function
				calculate= new Thread(new Calculate('9'));
				calculate.start();
				
			}
		});
		panel.add(btnNine);
		
		btnDivide = new JButton("/");
		//When the button / click
		btnDivide.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				//define Thread and start / button function
				calculate= new Thread(new Calculate('/'));
				calculate.start();
			}
		});
		panel.add(btnDivide);
		
		btnZero = new JButton("0");
		//When the button 0 click
		btnZero.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				//define Thread and start 0 button function
				calculate= new Thread(new Calculate('0'));
				calculate.start();
				
			}
		});
		panel.add(btnZero);
		
		btnPoint = new JButton(".");
		//When the button . click
		btnPoint.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				//define Thread and start . button function
				calculate= new Thread(new Calculate('.'));
				calculate.start();
			}
		});
		panel.add(btnPoint);
		
		btnRoot = new JButton("√");
		//When the button √ click
		btnRoot.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				//define Thread and start √ button function
				calculate= new Thread(new Calculate('√'));
				calculate.start();
				
			}
		});
		panel.add(btnRoot);
		
		btnResult = new JButton("=");
		//When the button = click
		btnResult.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				//define Thread and start = button function
				calculate= new Thread(new Calculate('='));
				calculate.start();
			}
		});
		panel.add(btnResult);
	}
	
	//define Calculate class
	class Calculate implements Runnable{
		char button;
		Calculate(char btn){
			
			button = btn;
		}

		@Override
		public void run() {
			switch(button) {
			case '1':
				number+="1";
				textOutput.setText(number); break;
			case '2':
				number+="2";
				textOutput.setText(number); break;
			case '3':
				number+="3";
				textOutput.setText(number); break;
			case '4':
				number+="4";
				textOutput.setText(number); break;
			case '5':
				number+="5";
				textOutput.setText(number); break;
			case '6':
				number+="6";
				textOutput.setText(number); break;
			case '7':
				number+="7";
				textOutput.setText(number); break;
			case '8':
				number+="8";
				textOutput.setText(number); break;
			case '9':
				number+="9";
				textOutput.setText(number); break;
			case '0':
				number+="0";
				textOutput.setText(number); break;
			case '.':
				number+=".";
				textOutput.setText(number); break;
			case 'C':
				number="";
				textOutput.setText(number); break;
			case '<':
				number = number.substring(0, number.length() - 1);
				textOutput.setText(number); break;
			case '+':
				save = number;
				number = "";
				operator="+";
				textOutput.setText(operator); break;
			case '-':
				save = number;
				number = "";
				operator="-";
				textOutput.setText(operator); break;
			case '*':
				save = number;
				number = "";
				operator="*";
				textOutput.setText(operator); break;
			case '%':
				save = number;
				number = "";
				operator="%";
				textOutput.setText(operator); break;
			case '√':
				save = number;
				number = "";
				double result = Double.parseDouble(save);
				//make squareRoot
				result =Math.sqrt(result);
				textOutput.setText(Double.toString(result)); break;
			case '=':
				if(operator == "+") {
					double num1 = Double.parseDouble(save);
					double num2 = Double.parseDouble(number);
					double cal = num1+num2;
					number = Double.toString(cal);
					//if end with .0 -> make integer expression
					if(cal%1==0.0) {
						number = number.substring(0, number.length() - 2);
					}
					textOutput.setText(number);
				}
				else if(operator == "-") {
					double num1 = Double.parseDouble(save);
					double num2 = Double.parseDouble(number);
					double cal = num1-num2;
					number = Double.toString(cal);
					//if end with .0 -> make integer expression
					if(cal%1==0.0) {
						number = number.substring(0, number.length() - 2);
					}
					textOutput.setText(number);
				}
				else if(operator == "*") {
					double num1 = Double.parseDouble(save);
					double num2 = Double.parseDouble(number);
					double cal = num1*num2;
					number = Double.toString(cal);
					//if end with .0 -> make integer expression
					if(cal%1==0.0) {
						number = number.substring(0, number.length() - 2);
					}
					textOutput.setText(number);
				}
				else if(operator == "/") {
					double num1 = Double.parseDouble(save);
					double num2 = Double.parseDouble(number);
					double cal = num1/num2;
					number = Double.toString(cal);
					//if end with .0 -> make integer expression
					if(cal%1==0.0) {
						number = number.substring(0, number.length() - 2);
					}
					textOutput.setText(number);
				}
				else if(operator == "%") {
					double num1 = Double.parseDouble(save);
					double num2 = Double.parseDouble(number);
					double cal = num1%num2;
					number = Double.toString(cal);
					//if end with .0 -> make integer expression
					if(cal%1==0.0) {
						number = number.substring(0, number.length() - 2);
					}
					textOutput.setText(number);
				}
			}
			if(number.length()>5) {
				System.out.println("Not allow more than 5 digits");
				number = number.substring(0, number.length() - 1);
				textOutput.setText(number);
			}
		}
	}
}

