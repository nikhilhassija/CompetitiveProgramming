a = input().replace("{", "").replace("}", "").replace(" ", "").replace(",", "")
print(len(set(list(a))))