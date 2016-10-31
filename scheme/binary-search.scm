#lang scheme

;;; https://en.wikipedia.org/wiki/Binary_search_algorithm

(define (binary-search value vector)
  (let helper ((low 0)
               (high (- (vector-length vector) 1)))
    (if (< high low)
        #f
        (let ((middle (quotient (+ low high) 2)))
          (cond ((> (vector-ref vector middle) value)
                 (helper low (- middle 1)))
                ((< (vector-ref vector middle) value)
                 (helper (+ middle 1) high))
                (else middle))))))

(binary-search 10 '#(0 5 10 15 20 25)) ;Returns the position of 10 which is 2 in this case
(binary-search 11 '#(0 5 10 15 20 25)) ;Returns false

