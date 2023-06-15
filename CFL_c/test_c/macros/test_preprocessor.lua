
print("made it here")
reset_template_tables()
variable_table['a'] = "1"

str = "this is a test"
result = Expand_text_stream(str)
print("result is ",result)

str = 'this is a test <<p_l, - ,a,"b","c" >> <<p,a>> result'
result = Expand_text_stream(str)
print("result is ",result)


os.exit(0)
