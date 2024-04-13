(define (sum-of-natural-numbers n)
  (if (= n 0)
      0
      (+ n (sum-of-natural-numbers (- n 1)))))

(display "Enter the value of N: ")
(define n (read))

(if (>= n 0)
    (begin
      (display "The sum of the first ")
      (display n)
      (display " natural numbers is ")
      (display (sum-of-natural-numbers n))
      (newline))
    (display "Please enter a non-negative number."))
