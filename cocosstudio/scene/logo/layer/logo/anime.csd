<GameFile>
  <PropertyGroup Name="anime" Type="Layer" ID="688f0a2c-fa69-4995-9da1-5bbcd74f190c" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="50" Speed="1.0000" ActivedAnimationName="show">
        <Timeline ActionTag="-404015065" Property="Position">
          <PointFrame FrameIndex="0" X="1104.0000" Y="560.0000">
            <EasingData Type="7" />
          </PointFrame>
          <PointFrame FrameIndex="20" X="1104.0000" Y="621.0000">
            <EasingData Type="3" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="-404015065" Property="Scale">
          <ScaleFrame FrameIndex="0" X="0.8000" Y="0.8000">
            <EasingData Type="7" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="20" X="1.0000" Y="1.0000">
            <EasingData Type="3" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-404015065" Property="RotationSkew">
          <ScaleFrame FrameIndex="0" X="0.0000" Y="0.0000">
            <EasingData Type="7" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="20" X="0.0000" Y="0.0000">
            <EasingData Type="3" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-404015065" Property="Alpha">
          <IntFrame FrameIndex="0" Value="0">
            <EasingData Type="7" />
          </IntFrame>
          <IntFrame FrameIndex="20" Value="255">
            <EasingData Type="3" />
          </IntFrame>
        </Timeline>
        <Timeline ActionTag="-1398605773" Property="Position">
          <PointFrame FrameIndex="20" X="1104.0000" Y="621.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="50" X="1104.0000" Y="621.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="-1398605773" Property="Scale">
          <ScaleFrame FrameIndex="10" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="20" X="1.0000" Y="1.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="50" X="2.5000" Y="2.5000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-1398605773" Property="RotationSkew">
          <ScaleFrame FrameIndex="10" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="20" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="50" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-1398605773" Property="AnchorPoint">
          <ScaleFrame FrameIndex="10" X="0.5000" Y="0.5000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="20" X="0.5000" Y="0.5000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="50" X="0.5000" Y="0.5000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-1398605773" Property="Alpha">
          <IntFrame FrameIndex="10" Value="0">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="20" Value="127">
            <EasingData Type="0" />
          </IntFrame>
          <IntFrame FrameIndex="50" Value="0">
            <EasingData Type="0" />
          </IntFrame>
        </Timeline>
        <Timeline ActionTag="-1398605773" Property="FileData">
          <TextureFrame FrameIndex="10" Tween="False">
            <TextureFile Type="MarkedSubImage" Path="scene/logo/layer/logo/logo_ray.png" Plist="scene/logo/layer/logo/atlas.plist" />
          </TextureFrame>
          <TextureFrame FrameIndex="20" Tween="False">
            <TextureFile Type="MarkedSubImage" Path="scene/logo/layer/logo/logo_ray.png" Plist="scene/logo/layer/logo/atlas.plist" />
          </TextureFrame>
        </Timeline>
        <Timeline ActionTag="-1398605773" Property="BlendFunc">
          <BlendFuncFrame FrameIndex="10" Tween="False" Src="770" Dst="771" />
          <BlendFuncFrame FrameIndex="20" Tween="False" Src="770" Dst="771" />
        </Timeline>
        <Timeline ActionTag="-1398605773" Property="FrameEvent">
          <EventFrame FrameIndex="50" Tween="False" Value="end" />
        </Timeline>
      </Animation>
      <AnimationList>
        <AnimationInfo Name="show" StartIndex="0" EndIndex="60">
          <RenderColor A="255" R="245" G="255" B="250" />
        </AnimationInfo>
      </AnimationList>
      <ObjectData Name="Layer" Tag="319" ctype="GameLayerObjectData">
        <Size X="2208.0000" Y="1242.0000" />
        <Children>
          <AbstractNodeData Name="logo" ActionTag="-404015065" Tag="320" IconVisible="False" PercentWidthEnable="True" PercentHeightEnable="True" PercentWidthEnabled="True" PercentHeightEnabled="True" HorizontalEdge="BothEdge" LeftMargin="854.0544" RightMargin="854.0544" TopMargin="468.4824" BottomMargin="468.4824" Scale9Width="500" Scale9Height="305" ctype="ImageViewObjectData">
            <Size X="499.8912" Y="305.0352" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="1104.0000" Y="621.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="0.2264" Y="0.2456" />
            <FileData Type="MarkedSubImage" Path="scene/logo/layer/logo/logo.png" Plist="scene/logo/layer/logo/atlas.plist" />
          </AbstractNodeData>
          <AbstractNodeData Name="logo_ray" ActionTag="-1398605773" Alpha="118" Tag="323" IconVisible="False" HorizontalEdge="BothEdge" VerticalEdge="BothEdge" LeftMargin="754.0000" RightMargin="754.0000" TopMargin="271.0000" BottomMargin="271.0000" ctype="SpriteObjectData">
            <Size X="700.0000" Y="700.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="1104.0000" Y="621.0000" />
            <Scale ScaleX="1.1000" ScaleY="1.1000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.5000" />
            <PreSize X="0.3170" Y="0.5636" />
            <FileData Type="MarkedSubImage" Path="scene/logo/layer/logo/logo_ray.png" Plist="scene/logo/layer/logo/atlas.plist" />
            <BlendFunc Src="770" Dst="771" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>