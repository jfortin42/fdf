# fdf

fdf is a program developped for my learning course at 42 school to view 2D topological maps in a 3D space.
<img align="center" src="http://image.noelshack.com/fichiers/2016/46/1479404070-fdf-42.png" width="100%" />
Several options are available (see [Shortcuts](https://github.com/jfortin42/fdf#shortcuts) section for more info)
* Move the 3D map
* Zoom in and zoom out
* Increase or decrease the depth factor
* Change color

## Install & launch
```bash
git clone https://github.com/jfortin42/fdf ~/fdf
cd ~/fdf && make && ./fdf
```
Launch the program with a parameter which is the name of the map you would like to open.<br />
You have example maps in the _test_maps_ folder. The map must be valid.

Example : ⇣
```bash
./fdf test_maps/42.fdf
```
## Shortcuts

<table width="100%">
<thead>
<tr>
<td width="40%" height="60px" align="center" cellpadding="0">
<strong>Description</strong>
</td>
<td width="10%" align="center" cellpadding="0">
<span style="width:70px">&nbsp;</span><strong>Key(s)</strong><span style="width:50px">&nbsp;</span>
</td>
</tr>
</thead>
<tbody>
<tr>
<td valign="top" height="30px">Close the program</td>
<td valign="top" align="center"><kbd>&nbsp;esc&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Move the map to the left/right</td>
<td valign="top" align="center"><kbd>&nbsp;◄&nbsp;</kbd> <kbd>&nbsp;►&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Move the map up/down</td>
<td valign="top" align="center"><kbd>&nbsp;▲&nbsp;</kbd> <kbd>&nbsp;▼&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Zoom in/zoom out</td>
<td valign="top" align="center"><kbd>&nbsp;+&nbsp;</kbd> <kbd>&nbsp;-&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Increase/decrease the depth factor</td>
<td valign="top" align="center"><kbd>&nbsp;*&nbsp;</kbd> <kbd>&nbsp;/&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Change to next/previous colors</td>
<td valign="top" align="center"><kbd>&nbsp;page up&nbsp;</kbd> <kbd>&nbsp;page down&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Reset the map</td>
<td valign="top" align="center"><kbd>&nbsp;0&nbsp;</kbd></td>
</tr>
</tbody>
</table>
## Contact & contribute
If you want to contact me, or fix/improve fdf, feel free to send me an e-mail at **jfortin@student.42.fr**
