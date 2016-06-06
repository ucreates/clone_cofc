<GameFile>
  <PropertyGroup Name="anime" Type="Layer" ID="f181d4d8-9a11-4f32-8e46-e787be554425" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="90" Speed="1.0000" ActivedAnimationName="fadein">
        <Timeline ActionTag="-404015065" Property="Position">
          <PointFrame FrameIndex="0" X="1104.0000" Y="496.8000">
            <EasingData Type="7" />
          </PointFrame>
          <PointFrame FrameIndex="60" X="1104.0000" Y="621.0000">
            <EasingData Type="3" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="-404015065" Property="Scale">
          <ScaleFrame FrameIndex="0" X="0.8000" Y="0.8000">
            <EasingData Type="7" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="60" X="1.0000" Y="1.0000">
            <EasingData Type="3" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-404015065" Property="RotationSkew">
          <ScaleFrame FrameIndex="0" X="0.0000" Y="0.0000">
            <EasingData Type="7" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="60" X="0.0000" Y="0.0000">
            <EasingData Type="3" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-404015065" Property="Alpha">
          <IntFrame FrameIndex="0" Value="0">
            <EasingData Type="7" />
          </IntFrame>
          <IntFrame FrameIndex="60" Value="255">
            <EasingData Type="3" />
          </IntFrame>
        </Timeline>
        <Timeline ActionTag="-1398605773" Property="Position">
          <PointFrame FrameIndex="65" X="1104.0000" Y="621.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="90" X="1104.0000" Y="621.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="-1398605773" Property="Scale">
          <ScaleFrame FrameIndex="40" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="65" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="90" X="2.5000" Y="2.5000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-1398605773" Property="RotationSkew">
          <ScaleFrame FrameIndex="40" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="65" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="90" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-1398605773" Property="AnchorPoint">
          <ScaleFrame FrameIndex="40" X="0.5000" Y="0.5000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="65" X="0.5000" Y="0.5000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="90" X="0.5000" Y="0.5000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-1398605773" Property="Alpha">
          <IntFrame FrameIndex="40" Value="0">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="65" Value="127">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="90" Value="0">
            <EasingData Type="0" />
          </IntFrame>
        </Timeline>
        <Timeline ActionTag="-1398605773" Property="FileData">
          <TextureFrame FrameIndex="40" Tween="False">
            <TextureFile Type="MarkedSubImage" Path="scene/logo/layer/logo_dummy/logo_ray.png" Plist="scene/logo/layer/logo_dummy/atlas.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="65" Tween="False">
            <TextureFile Type="MarkedSubImage" Path="scene/logo/layer/logo_dummy/logo_ray.png" Plist="scene/logo/layer/logo_dummy/atlas.plist" />
          </TextureFrame>
        </Timeline>
        <Timeline ActionTag="-1398605773" Property="BlendFunc">
          <BlendFuncFrame FrameIndex="40" Tween="False" Src="770" Dst="771" />
          <BlendFuncFrame FrameIndex="65" Tween="False" Src="770" Dst="771" />
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="fadein" StartIndex="0" EndIndex="90">
          <RenderColor A="255" R="245" G="255" B="250" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Layer" Tag="319" ctype="GameLayerObjectData">
        <Size X="2208.0000" Y="1242.0000" />
        <Children>
          <AbstractNodeData Name="logo" ActionTag="-404015065" Tag="320" IconVisible="False" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" HorizontalEdge="BothEdge" VerticalEdge="BothEdge" LeftMargin="854.0000" RightMargin="854.0000" TopMargin="468.5000" BottomMargin="468.5000" Scale9Width="500" Scale9Height="305" ctype="ImageViewObjectData">
            <Size X="500.0000" Y="305.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="1104.0000" Y="621.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="0.2264" Y="0.2456" />
            <FileData Type="MarkedSubImage" Path="scene/logo/layer/logo_dummy/logo_dummy.png" Plist="scene/logo/layer/logo_dummy/atlas.plist" />
          </AbstractNodeData>
          <AbstractNodeData Name="logo_ray" ActionTag="-1398605773" Alpha="0" Tag="323" IconVisible="False" HorizontalEdge="BothEdge" VerticalEdge="BothEdge" LeftMargin="754.0000" RightMargin="754.0000" TopMargin="271.0000" BottomMargin="271.0000" ctype="SpriteObjectData">
            <Size X="700.0000" Y="700.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="1104.0000" Y="621.0000" />
            <Scale ScaleX="2.5000" ScaleY="2.5000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="0.0000" Y="0.0000" />
            <FileData Type="MarkedSubImage" Path="scene/logo/layer/logo_dummy/logo_ray.png" Plist="scene/logo/layer/logo_dummy/atlas.plist" />
            <BlendFunc Src="770" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>