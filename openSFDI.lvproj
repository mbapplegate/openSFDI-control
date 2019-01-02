<?xml version='1.0' encoding='UTF-8'?>
<Project Type="Project" LVVersion="17008000">
	<Item Name="My Computer" Type="My Computer">
		<Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="server.tcp.enabled" Type="Bool">false</Property>
		<Property Name="server.tcp.port" Type="Int">0</Property>
		<Property Name="server.tcp.serviceName" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.tcp.serviceName.default" Type="Str">My Computer/VI Server</Property>
		<Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
		<Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
		<Property Name="specify.custom.address" Type="Bool">false</Property>
		<Item Name="expandInputParams.vi" Type="VI" URL="../expandInputParams.vi"/>
		<Item Name="Main.vi" Type="VI" URL="../Main.vi"/>
		<Item Name="stateCtrl.ctl" Type="VI" URL="../stateCtrl.ctl"/>
		<Item Name="switchLED.vi" Type="VI" URL="../switchLED.vi"/>
		<Item Name="testMatrixGen.vi" Type="VI" URL="../testMatrixGen.vi"/>
		<Item Name="Dependencies" Type="Dependencies">
			<Item Name="vi.lib" Type="Folder">
				<Item Name="Draw Flattened Pixmap.vi" Type="VI" URL="/&lt;vilib&gt;/picture/picture.llb/Draw Flattened Pixmap.vi"/>
				<Item Name="FixBadRect.vi" Type="VI" URL="/&lt;vilib&gt;/picture/pictutil.llb/FixBadRect.vi"/>
				<Item Name="Flatten Pixmap.vi" Type="VI" URL="/&lt;vilib&gt;/picture/pixmap.llb/Flatten Pixmap.vi"/>
				<Item Name="Image Type" Type="VI" URL="/&lt;vilib&gt;/vision/Image Controls.llb/Image Type"/>
				<Item Name="imagedata.ctl" Type="VI" URL="/&lt;vilib&gt;/picture/picture.llb/imagedata.ctl"/>
				<Item Name="IMAQ Create" Type="VI" URL="/&lt;vilib&gt;/vision/Basics.llb/IMAQ Create"/>
				<Item Name="Imaq Dispose" Type="VI" URL="/&lt;vilib&gt;/vision/Basics.llb/Imaq Dispose"/>
				<Item Name="IMAQ Image.ctl" Type="VI" URL="/&lt;vilib&gt;/vision/Image Controls.llb/IMAQ Image.ctl"/>
				<Item Name="IMAQ Write BMP File 2" Type="VI" URL="/&lt;vilib&gt;/vision/Files.llb/IMAQ Write BMP File 2"/>
				<Item Name="IMAQ Write File 2" Type="VI" URL="/&lt;vilib&gt;/vision/Files.llb/IMAQ Write File 2"/>
				<Item Name="IMAQ Write Image And Vision Info File 2" Type="VI" URL="/&lt;vilib&gt;/vision/Files.llb/IMAQ Write Image And Vision Info File 2"/>
				<Item Name="IMAQ Write JPEG File 2" Type="VI" URL="/&lt;vilib&gt;/vision/Files.llb/IMAQ Write JPEG File 2"/>
				<Item Name="IMAQ Write JPEG2000 File 2" Type="VI" URL="/&lt;vilib&gt;/vision/Files.llb/IMAQ Write JPEG2000 File 2"/>
				<Item Name="IMAQ Write PNG File 2" Type="VI" URL="/&lt;vilib&gt;/vision/Files.llb/IMAQ Write PNG File 2"/>
				<Item Name="IMAQ Write TIFF File 2" Type="VI" URL="/&lt;vilib&gt;/vision/Files.llb/IMAQ Write TIFF File 2"/>
				<Item Name="IMAQdx.ctl" Type="VI" URL="/&lt;vilib&gt;/userdefined/High Color/IMAQdx.ctl"/>
				<Item Name="LVRectTypeDef.ctl" Type="VI" URL="/&lt;vilib&gt;/Utility/miscctls.llb/LVRectTypeDef.ctl"/>
				<Item Name="NI_Vision_Acquisition_Software.lvlib" Type="Library" URL="/&lt;vilib&gt;/vision/driver/NI_Vision_Acquisition_Software.lvlib"/>
			</Item>
			<Item Name="controlVI.vi" Type="VI" URL="../controlVI.vi"/>
			<Item Name="deg2rad.vi" Type="VI" URL="../deg2rad.vi"/>
			<Item Name="genColormap.vi" Type="VI" URL="../genColormap.vi"/>
			<Item Name="genImageMatrix.vi" Type="VI" URL="../genImageMatrix.vi"/>
			<Item Name="getProjectionRes.vi" Type="VI" URL="../getProjectionRes.vi"/>
			<Item Name="niimaqdx.dll" Type="Document" URL="niimaqdx.dll">
				<Property Name="NI.PreserveRelativePath" Type="Bool">true</Property>
			</Item>
			<Item Name="nivision.dll" Type="Document" URL="nivision.dll">
				<Property Name="NI.PreserveRelativePath" Type="Bool">true</Property>
			</Item>
			<Item Name="nivissvc.dll" Type="Document" URL="nivissvc.dll">
				<Property Name="NI.PreserveRelativePath" Type="Bool">true</Property>
			</Item>
			<Item Name="projectSineWave.vi" Type="VI" URL="../projectSineWave.vi"/>
			<Item Name="selectMonitor.vi" Type="VI" URL="../selectMonitor.vi"/>
		</Item>
		<Item Name="Build Specifications" Type="Build"/>
	</Item>
</Project>
