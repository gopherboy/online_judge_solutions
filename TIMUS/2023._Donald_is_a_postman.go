package main
import "fmt"

func main() {
	var a int
	var b[1000] string 
	fmt.Scan(&a)
	for cnt:=a;cnt>0;cnt-- {
		fmt.Scan(&b[cnt-1])
	}
	current := 1
	step := 0
	for cnt:=a-1;cnt>=0;cnt-- {
		if b[cnt][0]=='A' || b[cnt][0]=='P' || b[cnt][0]=='O' || b[cnt][0]=='R' {
			if current == 2 {
				step += 1
			}else if current == 3 {
				step +=2 
			}
			current = 1
		}else if b[cnt][0]=='S' || b[cnt][0]=='M' || b[cnt][0]=='B' {
			if current != 2 {
				step++
			}
			current = 2
		}else {
			if current == 2 {
				step += 1
			}else if current == 1 {
				step +=2
			}
			current = 3
		}
		
	}
	fmt.Println(step)
}
