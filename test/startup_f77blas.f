      program main

      integer m, p, n, lda, ldb, ldc, i, j
      parameter (m=10, p=10, n=10)
      double precision a(m,p), b(p,n), c(m,n), alpha, beta
      character transa, transb

      transa = 'N'
      transb = 'N'
      lda = m
      ldb = p
      ldc = n
      alpha = 0.5
      beta = 2.0
      do i = 1, m
         do j = 1, p
            a(i,j) = 1.0
         end do
      end do
      do i = 1, p
         do j = 1, n
            b(i,j) = 2.0
         end do
      end do
      do i = 1, m
         do j = 1, n
            c(i,j) = 0.0
         end do
      end do

!234567890
      call dgemm(transa, transb, m, n, p, alpha,
     & a, lda, b, ldb, beta, c, ldc)

      end
 
