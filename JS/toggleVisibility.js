function toggleVisibility(id, id2)
{
	var var1 = document.getElementById(id);
	var var2 = document.getElementById(id2);
	if (var1.style.display == 'none')
	{
		var2.innerHTML = var2.innerHTML.replace("[+]","[-]");
		var1.style.display = 'block';
	}
	else
	{
		var2.innerHTML = var2.innerHTML.replace("[-]","[+]");
		var1.style.display = 'none';
	}
}