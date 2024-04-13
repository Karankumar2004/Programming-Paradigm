(define (factorial n)
  (if (= n 0)
      1
      (* n (factorial (- n 1)))))

(display "Enter a natural number: ")
(define num (read))
(display "Factorial of ")
(display num)
(display " is ")
(display (factorial num))
(newline)