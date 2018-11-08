a = [32, 12, 43, 243, 19, 54, 14, 20]

a.each_with_index do |num, i|
  next if i == 0
  key = a[i]
  j = i - 1
  while j >= 0 and a[j] > key
    a[j + 1] = a[j]
    j -= 1
  end
  a[j + 1] = key
end
puts a