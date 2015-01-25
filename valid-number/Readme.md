# Valid Number

[[LeetCode] valid-number](https://oj.leetcode.com/problems/valid-number/)

> Validate if a given string is numeric.
> 
> Some examples:
> "0" => true
> " 0.1 " => true
> "abc" => false
> "1 a" => false
> "2e10" => true
> Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.


----------



## State Change Table

State|INVALID|SPACE|CHAR_SIGN|DIGITAL|CHAR_DOT|CHAR_E|Note
-|-|-|-|-|-|-
0|-1|0|3|1|2|-1|SPACE
1|-1|8|-1|1|4|5|SPACE+DIGITAL
2|-1|-1|-1|4|-1|-1|SPACE+CHAR_DOT
3|-1|-1|-1|1|2|-1|SPACE+CHAR_SIGN
4|-1|8|-1|4|-1|5|SPACE+DIGITAL+CHAR_DOT
5|-1|-1|6|7|-1|-1|SPACE+DIGITAL+CHAR_DOT+CHAR_E
6|-1|-1|-1|7|-1|-1|SPACE+DIGITAL+CHAR_DOT+CHAR_E+CHAR_SIGN
7|-1|8|-1|7|-1|-1|SPACE+DIGITAL+CHAR_DOT+CHAR_E+DIGITAL
8|-1|8|-1|-1|-1|-1|SPACE+DIGITAL+CHAR_DOT+CHAR_E+DIGITAL+SPACE

## State Change Graph

![valid-number state change](https://github.com/mtHust/LeetCode/valid-number/valid-number.png)


### graphviz code

    	digraph valid_number_state_machine {
		rankdir=LR;
		size="20, 20"
		node [shape = doublecircle color="green"] LR_1 LR_4 LR_7 LR_8;
		node [shape = doublecircle color="red"] LR_E;
		node [shape = circle] LR_0 LR_2 LR_3 LR_4 LR_5 LR_6 ;
		node [shape=point] LR_S;

		LR_S -> LR_0;
		
		LR_0 -> LR_0 [ label = "space" ];
		LR_0 -> LR_1 [ label = "0~9" ];
		LR_0 -> LR_2 [ label = "dot" ];
		LR_0 -> LR_3 [ label = "+/-" ];
		LR_0 -> LR_E [ label = "e/E/invalid" ];
		
		LR_1 -> LR_1 [label = "0~9"];
		LR_1 -> LR_4 [label = "dot"];
		LR_1 -> LR_5 [label = "e/E"];
		LR_1 -> LR_8 [label = "+/-/space"];
		LR_1 -> LR_E [label = "invalid"];
		
		
		LR_2 -> LR_4 [ label = "0~9" ];
		LR_2 -> LR_E [ label = "dot/+/-/e/E/space/invalid" ];	
		
		LR_3 -> LR_1 [label = "0~9"];
		LR_3 -> LR_2 [label = "dot"];
		LR_3 -> LR_E [label = "+/-/e/E/space/invalid"];
		
		
		LR_4 -> LR_4 [label = "0~9"];
		LR_4 -> LR_5 [label = "e/E"];
		LR_4 -> LR_8 [label = "space"];
		LR_4 -> LR_E [label = "+/-/invalid"];
		
		LR_5 -> LR_6 [ label = "+/-" ];
		LR_5 -> LR_7 [ label = "0~9" ];
		LR_5 -> LR_E [ label = "e/E/space/invalid" ];
		
		LR_6 -> LR_7 [ label = "0~9" ];
		LR_6 -> LR_E [ label = "dot/+/-/e/E/space/invalid" ];
		
		LR_7 -> LR_7 [ label = "0~9" ];
		LR_7 -> LR_8 [ label = "space" ];
		LR_7 -> LR_E [ label = "dot/+/-/e/E/invalid" ];
		
		LR_8 -> LR_8 [ label = "space" ];
		LR_8 -> LR_E [ label = "dot/+/-/e/E/space/invalid" ];
	}



#Copyright
by maotinghust@gmail.com
at 2015/01/24